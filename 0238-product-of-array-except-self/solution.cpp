using namespace std;
#include <vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int prefix = 1;
        int postfix = 1;
        for (int i = 0; i < res.size(); i++){
            res[i] = prefix;
            prefix *= nums[i];            
        }
        for (int i = res.size() - 1; i >= 0; --i){
            res[i] *= postfix;
            postfix *= nums[i];
            
        }
        return res;
    }
};
