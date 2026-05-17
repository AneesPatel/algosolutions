class Solution {
public:
    void dfs(int i, vector<int>& path, vector<vector<int>>& res, vector<int>& nums){ 
        if(i >= nums.size()){
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        dfs(i + 1, path, res, nums);
        path.pop_back();
        dfs(i + 1, path, res, nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        dfs(0, path, res, nums);
        return res;
    }
};
