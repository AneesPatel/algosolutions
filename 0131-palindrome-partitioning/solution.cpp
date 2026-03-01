class Solution {
public:
    bool isPal(int l, int r, string& s){
        while(l < r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int index, vector<string>& path, vector<vector<string>>& res, string& s){
        if(index >= s.size()){
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i){
            if(isPal(index, i, s)){
                path.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, path, res, s);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, path, res, s);
        return res;
    }
};
