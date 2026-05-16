class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i){
            if(i >= 1 and nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 and nums[j] == nums[j - 1]){
                    continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r){
                    long long goal = (long long)target - nums[i] - nums[j] - nums[l] - nums[r]; 
                    if(goal == 0){
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l + 1 < nums.size() and nums[l - 1] == nums[l]){
                            l++;
                        }
                        while(r - 1 > l and nums[r + 1] == nums[r]){
                            r--;
                        }
                        
                    }
                    else if(goal > 0){
                        l++;
                    } else{
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
