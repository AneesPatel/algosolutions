class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 2){
                    q.push_back({r, c});
                }
            }
        }
        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                auto cur = q.front();
                int r = cur.first;
                int c = cur.second;
                q.pop_front();
                grid[r][c] = 2;
                for(auto dire : directions){
                    int nr = r + dire.first;
                    int nc = c + dire.second;
                    if(0 <= nr and 0 <= nc and nr < ROWS and nc < COLS and grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push_back({nr, nc});
                    }
                }

            }
            if(!q.empty()){
                time += 1;
            }
        }

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
