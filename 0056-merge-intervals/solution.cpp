class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> prev = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            auto cur = intervals[i];
            // 2 cases; 1: prev < cur insert prev continue; 2 : overlap merge;
            if(prev[1] < cur[0]){
                res.push_back(prev);
                prev = cur;
            }
            else{
                prev[0] = min(prev[0], cur[0]);
                prev[1] = max(prev[1], cur[1]);
            }
        }
        res.push_back(prev);
        return res;
    }
};
