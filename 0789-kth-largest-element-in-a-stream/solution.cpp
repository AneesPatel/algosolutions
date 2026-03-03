class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minq;
    int maxk;
public:
    KthLargest(int k, vector<int>& nums) {
        maxk = k;
        for (auto cur : nums){
            minq.push(cur);
        }
        while(minq.size() > k){
            minq.pop();
        }
    }
    
    int add(int val) {
        minq.push(val);
        if(minq.size() > maxk){
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
