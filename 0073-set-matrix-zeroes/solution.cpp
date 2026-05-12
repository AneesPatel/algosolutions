class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto r : rows){
            for (int c = 0; c < COL; ++c){
                matrix[r][c] = 0;
            }
        }
        for(auto c : cols){
            for (int r = 0; r < ROW; ++r){
                matrix[r][c] = 0;
            }
        }
    }
};
