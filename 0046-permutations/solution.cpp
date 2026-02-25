class Solution {
public:
    void backtrack(auto& path, auto& prevs, auto& res, const auto& nums){
        if(nums.size() == path.size()){
            res.push_back(path);
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(prevs.count(i)){
                continue;
            }
            path.push_back(nums[i]);
            prevs.insert(i);
            backtrack(path, prevs, res, nums);
            path.pop_back();
            prevs.erase(i);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> prevs;
        vector<vector<int>> res;
        vector<int> path;
        backtrack(path, prevs, res, nums);
        return res;
    }
};
