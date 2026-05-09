class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> replace;
    void rdfs(int r, int c, vector<vector<int>>& matrix){
        if(r >= ROW){
            return;
        }
        if(matrix[r][c] != 0){
            replace.push_back({r, c});
        }
        rdfs(r + 1, c, matrix);
    }
    void cdfs(int r, int c, vector<vector<int>>& matrix){
        if(c >= COL){
            return;
        }
        if(matrix[r][c] != 0){
            replace.push_back({r, c});
        }
        cdfs(r, c + 1, matrix);
    }
    void setZeroes(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();
        for(int r = 0; r < ROW; ++r){
            for(int c = 0; c < COL; ++c){
                if(matrix[r][c] == 0){
                    rdfs(0, c, matrix);
                    cdfs(r, 0, matrix);
                }
            }
        }
        for(const auto& cur : replace){
            matrix[cur[0]][cur[1]] = 0;
        }
    }
};
