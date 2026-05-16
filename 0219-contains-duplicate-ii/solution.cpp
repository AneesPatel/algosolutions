class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> prevs;
        // val to index;
        for(int i = 0; i < nums.size(); ++i){
            if(prevs.count(nums[i]) > 0 and (i - prevs[nums[i]]) <= k){
                return true;
            }
            prevs[nums[i]] = i;
        }
        return false;
    }
};
