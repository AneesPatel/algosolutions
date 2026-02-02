using namespace std;
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool rows[9][9] = {false};
       bool cols[9][9] = {false};
       bool boxes[9][9] = {false};
        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if (board[r][c] == '.') continue;
                int nums = board[r][c] - '1';
                int board_index = (r / 3) * 3 + (c / 3);
                if (rows[r][nums] || cols[c][nums] || boxes[board_index][nums]){
                    return false;
                }
                rows[r][nums] = true;
                cols[c][nums] = true;
                boxes[board_index][nums] = true;

            }
       }
       return true;
    }
};
