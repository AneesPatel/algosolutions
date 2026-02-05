class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        unordered_set<char> prevs = {};
        for (int r = 0; r < s.size(); r++){
            while (prevs.count(s[r])){
                prevs.erase(s[l]);
                l++;
            }

            prevs.insert(s[r]);

            if ((r - l + 1) > res){
                res = (r - l + 1);
            }
        }
        return res;
    }
};
