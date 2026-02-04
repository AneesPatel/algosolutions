#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> prevs = {};
        int longest = 0;
        for (int i = 0; i < heights.size(); ++i){
            while(!prevs.empty() and prevs.top().first > heights[i]){
                int height = prevs.top().first;
                prevs.pop();
                int width;
                if (prevs.empty()){
                    width = i;
                }
                else{
                    width = i - prevs.top().second - 1;
                }
                longest = max(longest, height * width);
            }
            prevs.push({heights[i], i});
        }
        while (!prevs.empty()){
            int height = prevs.top().first;
            prevs.pop();
            int width;
            if (prevs.empty()){
                width = heights.size();
            }
            else{
                width = heights.size() - prevs.top().second - 1;
                longest = max(longest, height * width);
            }
            longest = max(longest, height * width);
        }
        return longest;
    }
};
