class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxq;
        long long x; long long y; long long temp;
        for(int i = 0; i < points.size(); ++i){
            x = points[i][0];
            y = points[i][1];
            temp = x * x + y * y;
            if(maxq.size() < k){
                maxq.push({temp, i});
                continue;
            }
            if(maxq.top().first > temp){
                maxq.pop();
                maxq.push({temp, i});
            }

        }
        vector<vector<int>> res;
        while(!maxq.empty()){
            res.push_back(points[maxq.top().second]);
            maxq.pop();
        }

        return res;
    }
};
