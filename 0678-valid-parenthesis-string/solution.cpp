class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0;
        int maxopen = 0;
        for(char cur : s){
            if(cur == '('){
                minopen++;
                maxopen++;
            }
            if(cur == ')'){
                minopen -= 1;
                maxopen -= 1;
            }
            if(cur == '*'){
                minopen -= 1;
                maxopen += 1;

            }
            if(minopen < 0){
                minopen = 0;
            }
            if(maxopen < 0){
                return false;
            }
        }
        return minopen == 0;
    }
};
