class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);//end index of word
        dp[n] = true;
        for(int i = n; i >= 0; --i){
            for(auto word : wordDict){
                if((i + word.size()) <=n and s.substr(i, word.size()) == word and dp[i + word.size()]){
                    dp[i] = true;
                    break;
                }
            }
            
        }
        return dp[0];

    }
};
