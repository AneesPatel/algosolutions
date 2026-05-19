class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> prevs;
        for(auto& cur : nums1){
            prevs.insert(cur);
        }
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums2.size(); ++i){
            if(prevs.count(nums2[i]) > 0){
                return nums2[i];
            }
        }
        return -1;
    }
};
