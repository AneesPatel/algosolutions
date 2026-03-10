class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> prevs;
        for(auto x : nums){
            if(prevs.count(x)){
                return true;
            }
            prevs.insert(x);
        }
        return false;
    }
};
