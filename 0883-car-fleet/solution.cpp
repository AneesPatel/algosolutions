using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        stack<double> prevs = {};
        for (int i{0}; i < position.size(); ++i){
            double time = (double)(target - cars[i].first) / cars[i].second; 
            if (prevs.empty() or time > prevs.top()){
                prevs.push(time);
            }
        }
        return prevs.size();


    }
};
