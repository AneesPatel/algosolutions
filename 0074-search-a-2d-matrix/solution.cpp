class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int row = 0; row < matrix.size(); ++row){
            int l = 0;
            int r = matrix[row].size() - 1;
            if (matrix[row][r] < target){
                continue;
            }
            int mid;
            while(l <= r){
                mid = l + (r - l) / 2;
                if (matrix[row][mid] == target){
                    return true;
                }
                else if (target > matrix[row][mid]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
