class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map = {};
        for (int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (map.count(temp)){
                map[temp].push_back(strs[i]);
            }
            else{
                map[temp] = {strs[i]};
            }
        }
        vector<vector<string>> res = {};
        for (const auto& [key, value] : map) {
            res.push_back(value);
        }
        return res;

    }
};
