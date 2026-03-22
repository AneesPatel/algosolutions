class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int distance = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // pair<distance, node>
        unordered_set<int> visited;
        q.push({0, 0});

        while(visited.size() < points.size()){
            int curDistance = q.top().first;
            int curIndex = q.top().second;
            q.pop();

            if(visited.count(curIndex)){
                continue;
            }
            distance += curDistance;
            visited.insert(curIndex);

            for(int i = 0; i < points.size(); ++i){
                if(visited.count(i) == 0){
                    int y = points[curIndex][1];
                    int y1 = points[i][1];
                    int x = points[curIndex][0];
                    int x1 = points[i][0];
                    int tempDistance = abs(y - y1) + abs(x - x1);
                    q.push({tempDistance, i});
                }
            }
        }

        return distance;
    }
};
