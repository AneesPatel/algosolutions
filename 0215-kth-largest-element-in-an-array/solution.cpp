class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxq;
        for(auto cur: nums){
            maxq.push(cur);
        }
        int i = 1;
        while(!maxq.empty()){
            if(i == k){
                return maxq.top();
            }
            i++;
            maxq.pop();
        }
        return -1;
    }
};
