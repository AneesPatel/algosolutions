class Solution {
public:
    void backtrack(int index, vector<vector<int>>& res, vector<int>& path, vector<int>& nums){
        
        res.push_back(path);
            
        
        for(int i = index; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtrack(i + 1, res, path, nums);
            path.pop_back();

        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, res, path, nums);
        return res;
    }
};
