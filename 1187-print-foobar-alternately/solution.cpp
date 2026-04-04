#include <atomic>
#include <thread>

class FooBar {
private:
    int n;
    std::atomic<int> turn_{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (turn_.load(std::memory_order_acquire) != 0) {
                // LeetCode Fix: Surrender the CPU time-slice immediately
                // so the other thread can run and update the flag.
                std::this_thread::yield(); 
            }
            
            printFoo();
            turn_.store(1, std::memory_order_release);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (turn_.load(std::memory_order_acquire) != 1) {
                // LeetCode Fix: Surrender the CPU
                std::this_thread::yield();
            }
            
            printBar();
            turn_.store(0, std::memory_order_release);
        }
    }
};
