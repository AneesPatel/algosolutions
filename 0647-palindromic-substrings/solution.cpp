class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        for(int l = n - 1; l >= 0; --l){
            for(int r = l; r < n; ++r){
                if(memo[l][r] == true){
                    continue;
                }
                if(s[l] == s[r] and (r - l <= 2 or memo[l + 1][r - 1] == true)){
                    memo[l][r] = true;
                    res += 1;
                }
            }
        }

        return res;
    }
};
