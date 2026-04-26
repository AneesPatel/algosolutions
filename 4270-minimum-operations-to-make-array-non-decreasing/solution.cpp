class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total = 0;
        vector<int> res = nums;
        for(int i = 1; i < res.size(); ++i){
            if(res[i - 1] > res[i]){
                total += (res[i - 1] - res[i]);
            }
        }
        return total;
    }
};
