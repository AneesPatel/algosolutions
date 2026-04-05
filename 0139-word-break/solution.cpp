class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; --i){
            for(const auto& word : wordDict){
                if(i + word.size() <= n and dp[i + word.size()] == true and s.substr(i, word.size()) == word){
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};
