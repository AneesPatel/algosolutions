using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> prevs = {};
        vector<int> res(temperatures.size(), 0);
        
        for(int i = 0; i < temperatures.size(); i++){
            while (!prevs.empty() and temperatures[i] > temperatures[prevs.top()]){
                res[prevs.top()] = (i - prevs.top());
                prevs.pop();
            }
            prevs.push(i);
        }
        return res;
    }
};
