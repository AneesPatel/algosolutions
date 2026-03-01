class Solution {
public:
    void backtrack(int r, int qcount, vector<string>& path, unordered_set<int>& prevCol, unordered_set<int>& prevDiag, unordered_set<int>& prevNDiag, vector<vector<string>>& res, int n){
        if(qcount == n){
            res.push_back(path);
            return;
        }

        //for each col in row;
        for(int c = 0; c < n; ++c){
            if(prevCol.count(c) or prevDiag.count(c - r) or prevNDiag.count(c + r)){
                continue;
            }
            path[r][c] = 'Q';
            prevCol.insert(c);
            prevDiag.insert(c - r);
            prevNDiag.insert(c + r);
            backtrack(r + 1, qcount + 1, path, prevCol, prevDiag, prevNDiag, res, n);
            path[r][c] = '.';
            prevCol.erase(c);
            prevDiag.erase(c - r);
            prevNDiag.erase(c + r);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> prevCol;
        unordered_set<int> prevDiag;
        unordered_set<int> prevNDiag;
        vector<vector<string>> res;
        vector<string> path;
        string temp = "";
        for(int i = 0; i < n; ++i){
            temp = "";
            for(int j = 0; j < n; ++j){
                temp += ".";
            }
            path.push_back(temp);
        }
        backtrack(0, 0, path, prevCol, prevDiag, prevNDiag, res, n);
        return res;
    }
};
