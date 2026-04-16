class Solution {
public:
    int dp(int i, int j, string& s, string& t, vector<vector<int>>& memo){
        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        memo[i][j] = 0;
        if(s[i] == t[j]){
            memo[i][j] += dp(i + 1, j + 1, s, t, memo); 
        }
        memo[i][j] += dp(i + 1, j, s, t, memo);
        return memo[i][j]; 
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
        //have paths that are valid ONLY; ie only increment index of s and t if s == t else move s along(always move s along to find all diff disticnt subseq)
        return dp(0, 0, s, t, memo);

    }
};
