class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k = nums.size()/3;
        unordered_map<int, int> map; //int to count of int;
        for(auto& cur : nums){
            map[cur]++;
        }
        vector<int> res;
        for(auto& [num, count] : map){
            if(count > k){
                res.push_back(num);
            }
        }
        return res;
    }
};
