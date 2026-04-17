class Solution {
public:
    int dp(int i, int j, string& word1, string& word2, vector<vector<int>>& memo){
        if(i >= word1.size()){
            return word2.size() - j;
        }
        if(j >= word2.size()){
            return word1.size() - i;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        //4 cases
        int temp = INT_MAX;
        if(word1[i] == word2[j]){
            temp = min(temp, dp(i + 1, j + 1, word1, word2, memo));
        }
        temp = min(temp, dp(i, j + 1, word1, word2, memo) + 1); // insert
        temp = min(temp, dp(i + 1, j + 1, word1, word2, memo) + 1); // replace
        temp = min(temp, dp(i + 1, j, word1, word2, memo) + 1); // delete
        memo[i][j] = temp;
        return memo[i][j];

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dp(0, 0, word1, word2, memo);
    }
};
