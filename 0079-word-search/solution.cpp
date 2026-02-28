class Solution {
public:
    int ROWS;
    int COLS;
    bool backtrack(int r, int c, int wordindex, vector<vector<char>>& board, const string& word){
        if (wordindex == word.size()){
            return true;    
        }
        if(r < 0 or c < 0 or ROWS <= r or COLS <= c or board[r][c] != word[wordindex]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        if(backtrack(r + 1, c, wordindex + 1, board, word) or backtrack(r, c + 1, wordindex + 1, board, word) or backtrack(r - 1, c, wordindex + 1, board, word) or backtrack(r, c - 1, wordindex + 1, board, word)){
            return true;
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        string path = "";
        for(int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if(board[r][c] == word[0] and backtrack(r, c, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
