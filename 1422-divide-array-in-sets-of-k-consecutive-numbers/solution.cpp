class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0){
            return false;
        }
        unordered_map<int, int> count;
        for(const auto& cur : nums){
            count[cur]++;
        }
        sort(nums.begin(), nums.end());
        for(auto cur : nums){
            if(count[cur] > 0){
                for(int i = 0; i < k; ++i){
                    if(count[cur + i] <= 0){
                        return false;
                    }
                    count[cur + i]--;
                }
            }
        }
        return true;
    }
};
