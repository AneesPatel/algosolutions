class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto cur : nums){
            res = res ^ cur;
        }
        return res;
    }
};
