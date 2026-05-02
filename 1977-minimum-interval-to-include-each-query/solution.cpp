class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq; // size, right value
        int i = 0;
        vector<pair<int, int>> newqueries;
        for(int j = 0; j < queries.size(); ++j){
            newqueries.push_back({queries[j], j});
        }
        sort(intervals.begin(), intervals.end());
        sort(newqueries.begin(), newqueries.end());
        unordered_map<int, int> res; // index, val
        for(auto cur : newqueries){
            auto q = cur.first;
            while(i < intervals.size() and intervals[i][0] <= q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                minq.push({r - l + 1, r});
                ++i;
            }
            while(!minq.empty() and minq.top().second < q){
                minq.pop();
            }
            if(minq.empty()){
                res[cur.second] = -1;
            }
            else{
                res[cur.second] = minq.top().first;
            }
            
        }
        vector<int> res2(queries.size());
        for(auto& [index, val] : res){
            res2[index] = val;
        }
        return res2;
    }
};
