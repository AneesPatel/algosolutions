class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int longest = 0; int longestindex = 0;
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(s[j] == s[i] and (j - i <= 2 or dp[i + 1][j - 1] == true)){
                    dp[i][j] = true;
                    if(j - i + 1 > longest){
                        longest = j - i + 1;
                        longestindex = i;
                    }
                }
            }
        }
        return s.substr(longestindex, longest);
    }
};
