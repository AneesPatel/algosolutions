class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for(auto cur : nums){
            i = i ^ cur;
        }
        return i;
    }
};
