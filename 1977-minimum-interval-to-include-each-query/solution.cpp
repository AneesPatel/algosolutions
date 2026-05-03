class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
        // size, rightindex
        vector<pair<int, int>> nqueries;
        for(int i = 0; i < queries.size(); ++i){
            nqueries.push_back({queries[i], i});
        }
        int i = 0;
        sort(nqueries.begin(), nqueries.end());
        sort(intervals.begin(), intervals.end());
        for(auto q : nqueries){
            int val = q.first;
            int index = q.second;
            while(i < intervals.size() and val >= intervals[i][0]){
                minq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while(!minq.empty() and minq.top().second < q.first){
                minq.pop();
            }
            if(!minq.empty()){
                res[index] = minq.top().first;
            }
            else{
                res[index] = -1;
            }
        }
        return res;
    }
};
