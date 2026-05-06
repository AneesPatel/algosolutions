class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp(int n, int k, int score, int target, vector<vector<int>>& memo){
        if(score > target){
            return 0;
        }
        if(n == 0){
            if(score == target){
                return 1;
            }
            return 0;
        }
        if(memo[n][score] != -1){
            return memo[n][score];
        }

        int temp = 0;
        for(int i = 1; i <= k; ++i){
            temp = (temp + dp(n - 1, k, score + i, target, memo)) % MOD;
        }
        memo[n][score] = temp;
        return memo[n][score];

    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return dp(n, k, 0, target, memo);
    }
};
