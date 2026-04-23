#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <optional>
#include <array>
#include <unordered_map>

struct alignas(64) ThreadState {
    std::atomic<bool> done{false};
    std::atomic<int> result_idx1{-1};
    std::atomic<int> result_idx2{-1};
};

// 2. The Sharded Hash Map
class ShardedMap {
    static constexpr size_t NUM_SHARDS = 16;
    struct Shard {
        std::shared_mutex rw_lock; 
        std::unordered_map<int, int> data;
        char padding[64]; // Cache line padding
    };
    std::array<Shard, NUM_SHARDS> shards;

    size_t get_shard_idx(int key) const {
        // Simple modulo hashing to distribute across shards
        return std::hash<int>{}(key) % NUM_SHARDS;
    }

public:
    void insert(int key, int value) {
        auto& shard = shards[get_shard_idx(key)];
        // Explicitly templated for strict LeetCode C++17 compliance
        std::unique_lock<std::shared_mutex> lock(shard.rw_lock);
        shard.data[key] = value;
    }

    std::optional<int> find(int key) {
        auto& shard = shards[get_shard_idx(key)];
        std::shared_lock<std::shared_mutex> lock(shard.rw_lock);
        auto it = shard.data.find(key);
        if (it != shard.data.end()) return it->second;
        return std::nullopt;
    }
};

class Solution {
    static void worker_routine(const std::vector<int>& nums, int target, int start_idx, int end_idx, 
                               ShardedMap& shared_map, ThreadState& global_state) {
        
        for (int i = start_idx; i < end_idx; ++i) {
            // Check if another thread already won the race
            if (global_state.done.load(std::memory_order_relaxed)) return;

            int complement = target - nums[i];
            auto found_idx = shared_map.find(complement);
            
            if (found_idx.has_value()) {
                // Attempt to atomically publish the winning indices
                bool expected = false;
                if (global_state.done.compare_exchange_strong(expected, true, std::memory_order_release)) {
                    global_state.result_idx1.store(found_idx.value(), std::memory_order_relaxed);
                    global_state.result_idx2.store(i, std::memory_order_relaxed);
                }
                return;
            }

            shared_map.insert(nums[i], i);
        }
    }

public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int num_threads = std::thread::hardware_concurrency();
        if (num_threads == 0) num_threads = 4; // Fallback if the container lies
        
        num_threads = std::min(num_threads, static_cast<int>(nums.size()));

        const int n = nums.size();
        const int chunk_size = (n + num_threads - 1) / num_threads;

        // Instantiate state LOCALLY so it resets perfectly between LeetCode test cases
        ThreadState global_state;
        ShardedMap shared_map;
        std::vector<std::thread> workers;

        // Partition and conquer
        for (int i = 0; i < num_threads; ++i) {
            int start_idx = i * chunk_size;
            int end_idx = std::min(start_idx + chunk_size, n);
            
            if (start_idx < end_idx) {
                workers.emplace_back(worker_routine, std::ref(nums), target, 
                                     start_idx, end_idx, std::ref(shared_map), std::ref(global_state));
            }
        }

        // Barrier
        for (auto& t : workers) {
            if (t.joinable()) t.join();
        }

        // Acquire results
        if (global_state.done.load(std::memory_order_acquire)) {
            return {global_state.result_idx1.load(), global_state.result_idx2.load()};
        }

        return {}; 
    }
};
