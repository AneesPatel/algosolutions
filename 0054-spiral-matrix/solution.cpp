class Solution {
public:
    int ROW;
    int COL;
    int size;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int r, int c, int dir, vector<int>& res, vector<vector<int>>& matrix){
        if(res.size() == size){
            return;
        }
        res.push_back(matrix[r][c]);
        matrix[r][c] = INT_MAX;

        int nr = r + directions[dir][0];
        int nc = c + directions[dir][1];
        
        if(nr >= ROW or nc >= COL or nr < 0 or nc < 0 or matrix[nr][nc] == INT_MAX){
            dir = (1 + dir) % 4;
            nr = r + directions[dir][0];
            nc = c + directions[dir][1];
        }
        dfs(nr, nc, dir, res, matrix);
        

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();
        size = ROW * COL;
        vector<int> res;
        dfs(0, 0, 0, res, matrix);
        return res;
    }
};
