using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
static const int speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 and (nums[i] == nums[i - 1])) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r){
                int sum = nums[l] + nums[r] + nums[i];
                if (sum > 0){
                    r--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    vector<int> temp = {nums[l], nums[r], nums[i]};
                    res.push_back(temp);
                    while(l < r and nums[l + 1] == nums[l]) l++;
                    while(l < r and nums[r - 1] == nums[r]) r--;
                    r--;
                    l++;
                }
            }
        }
        return res;
        
    }
};
