class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int index, vector<int>& path, const vector<int>& nums){
        //vector<int> curpath = path;
        res.push_back(path);

        for (int i = index; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtrack(i + 1, path, nums);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> path;
        backtrack(0, path, nums);
        return res;
    }
};
