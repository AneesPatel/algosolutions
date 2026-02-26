class Solution {
public:
    void backtrack(vector<int>& path, vector<vector<int>>& res, int index, const vector<int>& nums){
        res.push_back(path);

        for(int i = index; i < nums.size(); ++i){
            if(index > nums.size()){
                return;
            }
            if((index < i) and (nums[i] == nums[i - 1])){
                continue;
            }
            path.push_back(nums[i]);
            backtrack(path, res, i + 1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(path, res, 0, nums);
        return res;
    }
};
