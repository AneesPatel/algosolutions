class Solution {
public:
    int dp(int i, int j, string& s, string& p, vector<vector<int>>& memo){
        if(i >= s.size() and j >= p.size()){
            return 1;
        }
        if(j >= p.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int temp = 0;
        bool valid = i < s.size() and (s[i] == p[j] or p[j] == '.');
        if(j <= p.size() and p[j + 1] == '*'){
            if((valid and dp(i + 1, j, s, p, memo)) or dp(i, j + 2, s, p, memo)){
                temp = 1;
            }
        } else if(valid){
            if(dp(i + 1, j + 1, s, p, memo)){
                temp = 1;
            }
        }
        memo[i][j] = temp;
        return memo[i][j];
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0, s, p, memo);
    }
};
