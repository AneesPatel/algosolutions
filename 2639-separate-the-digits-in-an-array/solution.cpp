class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> res;
        for(auto cur : nums){
            if(cur > 9){
                std::string temp = std::to_string(cur);
                for(const auto& curChar : temp){
                    res.push_back(curChar - '0');
                }
            } else{
                res.push_back(cur);
            }
        }
        return res;
    }
};
