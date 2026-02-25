class Solution {
public:
    void backtrack(int remaining, int i, vector<int>& path, const vector<int>& nums, vector<vector<int>>& res){
        if (remaining == 0){
            res.push_back(path);
            return;
        }

        if(remaining < 0 or i >= nums.size()){
            return;
        }
        path.push_back(nums[i]);
        backtrack(remaining - nums[i], i, path, nums, res);
        path.pop_back();
        backtrack(remaining, i + 1, path, nums, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path = {};
        backtrack(target, 0, path, candidates, res);
        return res;
    }
};
