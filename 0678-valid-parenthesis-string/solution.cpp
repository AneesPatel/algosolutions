class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0;
        int maxopen = 0;
        for(auto cur : s){
            if(cur == '('){
                minopen++;
                maxopen++;
            }
            if(cur == ')'){
                minopen--;
                maxopen--;
            }
            if(cur == '*'){
                minopen--;
                maxopen++;
            }
            if(maxopen < 0){
                return false;
            }
            if(minopen < 0){
                minopen = 0;
            }
        }
        return minopen == 0;
    }
};
