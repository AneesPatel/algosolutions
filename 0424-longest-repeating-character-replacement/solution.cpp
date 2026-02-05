class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> prevs = {};
        for (auto cur : s){
            prevs[cur] = 0;
        }
        for (int r = 0; r < s.size(); r++){
            prevs[s[r]] = prevs[s[r]] + 1;
            int maxValue = 0;
            for(auto const& cur: prevs){
                if (cur.second > maxValue){
                    maxValue = cur.second;
                }
            }

            while (((r - l + 1) - maxValue) > k){
                prevs[s[l]] -= 1;
                l += 1;
            }
            if (res < (r - l + 1)){
                res = (r - l + 1);
            }
        }
        return res;
    }
};
