class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int res = 0;
        auto prev = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            auto cur = intervals[i];
            if(prev[1] > cur[0]){
                res++;
                prev[1] = min(cur[1], prev[1]);
            }
            else{
                prev = cur;
            }

        }
        return res;
    }
};
