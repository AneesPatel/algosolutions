class KthLargest {
private:
    priority_queue<int, std::vector<int>, std::greater<int>> minq;
    int k_size;
public:
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for (auto cur:nums){
            minq.push(cur);
        }
        while(minq.size() > k){
            minq.pop();
        }
    }
    
    int add(int val) {
        minq.push(val);
        if(minq.size() > k_size){
            minq.pop();
        }
        return minq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
