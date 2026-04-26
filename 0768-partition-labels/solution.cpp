class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); ++i){
            last[s[i]] = i;
        }
        int endmax = 0;
        int size = 0;
        for(int i = 0; i < s.size(); ++i){
            size++;
            endmax = max(endmax, last[s[i]]);
            if(i == endmax){
                res.push_back(size);
                size = 0;

            }
        }
        
        return res;
    }
};
