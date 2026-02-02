using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> todo; // Use long to handle potential overflow during intermediate steps
        
        for (const string& cur : tokens) {
            // Only treat as operator if string length is 1 AND it's a symbol
            if (cur.size() == 1 && (cur[0] == '+' || cur[0] == '-' || cur[0] == '*' || cur[0] == '/')) {
                long prev1 = todo.top(); todo.pop();
                long prev2 = todo.top(); todo.pop();
                
                if (cur[0] == '+') todo.push(prev2 + prev1);
                else if (cur[0] == '-') todo.push(prev2 - prev1);
                else if (cur[0] == '*') todo.push(prev2 * prev1);
                else if (cur[0] == '/') todo.push(prev2 / prev1);
            } 
            else {
                // This handles "10", "-11", "5", etc.
                todo.push(stol(cur));
            }
        }
        return (int)todo.top();
    }
};
