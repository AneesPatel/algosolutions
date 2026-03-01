class Solution {
public:
    vector<string> numsMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int index, string& path, vector<string>& res, string& digits){
        if (path.size() == digits.size()){
            res.push_back(path);
            return;
        } 
        string curdigit(1, digits[index]);
        for(auto cur : numsMap[stoi(curdigit)]){
            path.push_back(cur);
            backtrack(index + 1, path, res, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string> res;
       string path = "";
       backtrack(0, path, res, digits);
       return res; 
    }
};
