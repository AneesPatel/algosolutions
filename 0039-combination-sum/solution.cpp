class Solution {
public:
    void backtrack(int index, int remaining, vector<int>& path, const vector<int>& nums, vector<vector<int>>& res){
        if(remaining == 0){
            res.push_back(path);
            return;
        }
        if(remaining < 0){
            return;
        }
        for(int i = index; i < nums.size(); ++i){

            path.push_back(nums[i]);
            backtrack(i, remaining - nums[i], path, nums, res);
            path.pop_back();
            //backtrack(index, remaining - nums[i], path, nums, res);
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, target, path, candidates, res);
        return res;
    }
};
