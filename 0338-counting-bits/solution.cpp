class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int msb = 1;
        for(int i = 1; i <= n; ++i){
            if(msb * 2 == i){
                msb = i;
            }
            dp[i] = 1 + dp[i - msb];
        }
        return dp;
    }
};
