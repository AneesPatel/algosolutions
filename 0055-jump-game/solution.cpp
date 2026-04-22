class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i > max_reach){
                return false;
            }
            max_reach = max(nums[i] + i, max_reach);
            if(max_reach >= nums.size()){
                return true;
            }
        }
        return true;
    }
};
