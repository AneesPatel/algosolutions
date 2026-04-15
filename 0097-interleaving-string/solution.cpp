class Solution {
public:
    int dp(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& memo){
        if(i >= s1.size() and j >= s2.size() and k >= s3.size()){
            return 1;
        }
        if(i >= s1.size() and j >= s2.size() and k < s3.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(i >= s1.size() and j < s2.size() and k < s3.size()){
            if(s3[k] == s2[j]){
                memo[i][j] = dp(i, j + 1, k + 1, s1, s2, s3, memo);
                return memo[i][j];
            } else{
                return 0;
            }
            
        }
        if(i < s1.size() and j >= s2.size() and k < s3.size()){
            if(s3[k] == s1[i]){
                memo[i][j] = dp(i + 1, j, k + 1, s1, s2, s3, memo);
                return memo[i][j];
            } else{
                return 0;
            }
            
        }
        int temp = 0;
        if(s3[k] == s1[i]){
            if(dp(i + 1, j, k + 1, s1, s2, s3, memo) == 1){
                temp = 1;
            }
        }
        if(s3[k] == s2[j]){
           if(dp(i, j + 1, k + 1, s1, s2, s3, memo) == 1){
                temp = 1;
            }
        }
        memo[i][j] = temp;
        return memo[i][j];

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1)); // -1 = not seen, 0 = false, 1 = seen
        int temp = dp(0, 0, 0, s1, s2, s3, memo);
        if(temp == 1){
            return true;
        }
        return false;
    }
};
