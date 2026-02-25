class Solution {
public:
    void backtrack(int remaining, int index, vector<vector<int>>& res, vector<int>& path, const vector<int>& nums){
        if(remaining == 0){
            res.push_back(path);
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            if (index >= nums.size() or remaining < 0){
                return;
            }
            if((index < i) and (nums[i] == nums[i - 1])){
                continue;
            }
            if(nums[i] > remaining){
                return;
            }
            path.push_back(nums[i]);
            backtrack(remaining - nums[i], i + 1, res, path, nums);
            path.pop_back();
            //backtrack(remaining, i + 1, res, path, nums);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path = {};
        backtrack(target, 0, res, path, candidates);
        return res;
    }
};
