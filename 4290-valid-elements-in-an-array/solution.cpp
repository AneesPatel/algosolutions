class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1){
            return nums;
        }
        vector<int> right_max(n);
        right_max[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i){
            right_max[i] = max(right_max[i + 1], nums[i]);
        }
        vector<int> res;
        int left_max = nums[0];
        for(int i = 0; i < n; ++i){
            if(i == 0 or i == n - 1){
                res.push_back(nums[i]);
            }else{
                bool left = (nums[i] > left_max);
                bool right =  (nums[i] > right_max[i + 1]);
                if(left or right){
                 res.push_back(nums[i]);       
                }
            }
            if(nums[i] > left_max){
                left_max = nums[i];
            }
            
        }
        return res;
    }
};
