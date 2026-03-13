class Solution {
public:
    int ROWS;
    int COLS;
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r < 0 or c < 0 or r >= ROWS or c >= COLS or board[r][c] != 'O'){
            return;
        }
        board[r][c] = '#';
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        for(int r = 0; r < ROWS; ++r){
            if(board[r][0] == 'O'){
                dfs(r, 0, board);
                board[r][0] = '#';
            }
            if(board[r][COLS - 1] == 'O'){
                dfs(r, COLS - 1, board);
                board[r][COLS - 1] = '#';
            }
        }
        for(int c = 0; c < COLS; ++c){
            if(board[0][c] == 'O'){
                dfs(0, c, board);
                board[0][c] = '#';
            }
            if(board[ROWS - 1][c] == 'O'){
                dfs(ROWS - 1, c, board);
                board[ROWS - 1][c] = '#';
            }
        }


        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if (board[r][c] == '#'){
                    board[r][c] = 'O';
                }
                
            }
        }
    }
};
