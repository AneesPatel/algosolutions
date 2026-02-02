using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> para = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> stack = {};
        for(char cur:s){
            if (para.count(cur)){
                stack.push(cur);
            }
            else{
                if(stack.empty()){
                    return false;
                }
                if (para[stack.top()] == cur){
                    stack.pop();
                }
                else{
                    return false;
                }
            }

        }

        if(stack.empty()){
            return true;
        }
        return false;
    }
};
