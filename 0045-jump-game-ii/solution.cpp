class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int longest = 0; 
        int jump = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            longest = max(longest, i + nums[i]);
            if(i == l){
                jump++;
                l = longest;
            }

        }
        return jump;
    }
};
