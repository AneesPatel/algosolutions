class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0){
            return "";
        }
        unordered_map<char, int> needmap;
        for (char cur:t){
            needmap[cur]++;
        }
        int need = needmap.size();
        int have = 0;
        unordered_map<char, int> havemap;
        int reslen = INT_MAX;
        int minLen = 0;
        int l = 0;
        for(int r = 0; r < s.size(); ++r){
            havemap[s[r]]++;
            if (havemap[s[r]] == needmap[s[r]]){
                have++;
            }
            while(have == need){
                if ((r - l + 1) < reslen){
                    reslen = (r - l + 1);
                    minLen = l;
                }
                havemap[s[l]] -= 1;
                if (havemap[s[l]] < needmap[s[l]]){
                    have--;
                }
                l++;
            }

        }
        if (reslen == INT_MAX){
            return "";
        }
        else{
            return s.substr(minLen, reslen);
        }

    }
};
