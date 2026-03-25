class Solution {
public:
    void backtrack(int index, vector<int>& path, vector<vector<int>>& res, vector<int>& nums, unordered_set<int>& visited){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if (visited.count(nums[i])) continue;
            path.push_back(nums[i]);
            visited.insert(nums[i]);
            backtrack(i + 1, path, res, nums, visited);
            visited.erase(nums[i]);
            path.pop_back();

        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        unordered_set<int> visited;
        backtrack(0, path, res, nums, visited);
        return res;
    }
};
