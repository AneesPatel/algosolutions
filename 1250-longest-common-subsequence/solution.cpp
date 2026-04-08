class Solution {
public:
    int dp(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){
        if(i >= text1.size() or j >= text2.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        if(text1[i] == text2[j]){
            memo[i][j] = dp(i + 1, j + 1, text1, text2, memo) + 1;
        }
        else{
            memo[i][j] = max(dp(i + 1, j, text1, text2, memo), dp(i, j + 1, text1, text2, memo));
        }
        
        return memo[i][j];

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        //memo[i][j] = longest substring so far at index;
        return dp(0, 0, text1, text2, memo);
    }
};
