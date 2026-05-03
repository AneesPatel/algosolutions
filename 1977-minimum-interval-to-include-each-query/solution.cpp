class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size(), -1);
        vector<pair<int, int>> nqueries;
        //<val, orignal index>
        for(int i = 0; i < queries.size(); ++i){
            nqueries.push_back({queries[i], i});
        }
        sort(nqueries.begin(), nqueries.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
        //minq = pair<size, rightvalue>
        int i = 0;
        for(auto& q : nqueries){
            int val = q.first;
            int index = q.second;
            //populate while loop
            while(i < intervals.size() and intervals[i][0] <= val){
                minq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            //delete while loop
            while(!minq.empty() and val > minq.top().second){
                minq.pop();
            }
            if(!minq.empty()){
                res[index] = minq.top().first;
            }
        }
        return res;
    }
};
