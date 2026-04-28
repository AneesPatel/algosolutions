class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); ++i){
            map[s[i]] = i;
        }
        int cur = 0;
        int size = 0;
        vector<int> res;
        for(int i = 0; i < s.size(); ++i){
            cur = max(cur, map[s[i]]);
            size++;
            if(cur == i){
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
