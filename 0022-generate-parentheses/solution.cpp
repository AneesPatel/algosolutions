class Solution {
public:
    void backtrack(int open, int closed, string& path, const int& n, vector<string>& res){
        if(path.size() == n * 2){
            res.push_back(path);
        }
        if(open < n){
            string temp = path;
            path += '(';
            backtrack(open + 1, closed, path, n, res);
            path = temp;
        }
        if(closed < open){
            string temp = path;
            path += ')';
            backtrack(open, closed + 1, path, n, res);
            path = temp;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        backtrack(0, 0, path, n, res);
        return res;
    }
};
