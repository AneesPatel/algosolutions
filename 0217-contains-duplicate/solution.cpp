class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> prev = {};
        for(int i = 0; i < nums.size(); i++){
            if (prev.count(nums[i])){
                return true;
            }
            prev.insert(nums[i]);
        }
        return false;
    }
};
