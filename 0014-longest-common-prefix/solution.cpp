class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        if(strs.size() == 0){
            return "";
        }
        std::string res = "";
        int same = INT_MAX;
        for(int i = 1; i < strs.size(); ++i){
            int j = 0;
            int temp = 0;
            while(strs[i][j] == strs[0][j] and j < strs[i].size() and j < strs[0].size()){
                j++;
                temp++;

            }
            if(temp < same){
                res = strs[i].substr(0, temp);
                same = temp;
            }
        }
        return res;

    }
};
