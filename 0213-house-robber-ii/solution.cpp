class Solution {
public:
    int dp(int i, vector<int>& nums, vector<int>& memo){
        if(i >= nums.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        memo[i] = max(nums[i] + dp(i + 2, nums, memo), dp(i + 1, nums, memo));
        return memo[i];
    }
    int helper(vector<int>& nums){
        vector<int> memo(nums.size(), -1);
        return dp(0, nums, memo);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums.size() == 2){
            return max(nums[1], nums[0]);
        }
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(helper(nums1), helper(nums2));
    }
};
