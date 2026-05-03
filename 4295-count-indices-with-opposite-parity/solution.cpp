class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            bool ieven = isEven(nums[i]);
            int count = 0;
            for(int j = i; j < nums.size(); ++j){
                bool jeven = isEven(nums[j]);
                if(ieven != jeven){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    bool isEven(int i){
        return ((i % 2) == 0);
    }
};
