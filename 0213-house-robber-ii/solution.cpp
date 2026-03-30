class Solution {
public:
    int n;
    int dp(int i, vector<int>& memo, vector<int>& nums){
        if(i >= n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        
        memo[i] = max(nums[i] + dp(i + 2, memo, nums), dp(i + 1, memo, nums));
        return memo[i]; 

    }
    int helper(vector<int>& nums){
        n = nums.size();
        vector<int> memo(n, -1);
        return dp(0, memo, nums);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(helper(nums1), helper(nums2));
    }
};
