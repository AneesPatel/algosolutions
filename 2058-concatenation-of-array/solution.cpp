class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        for(auto cur : nums){
            res.push_back(cur);
        }
        for(auto cur : nums){
            res.push_back(cur);
        }
        return res;
    }
};
