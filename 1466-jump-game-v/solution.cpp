class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); 
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        vector<int> dp(n, 1);
        int max_res = 1;
        for (int i : indices) {
            for (int j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            for (int j = i + 1; j <= min(n - 1, i + d) && arr[j] < arr[i]; ++j) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            max_res = max(max_res, dp[i]);
        }
        
        return max_res;
    }
};
