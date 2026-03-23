class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, vector<pair<int, int>>> adjMap;
        for(auto time : times){
            adjMap[time[0]].push_back({time[1], time[2]});
        }
        q.push({0, k});
        unordered_set<int> visited;
        int longest = 0;
        while(!q.empty()){
            int curDistance = q.top().first;
            int curNode = q.top().second;
            q.pop();
            if(visited.count(curNode)){
                continue;
            }
            if(curDistance > longest){
                longest = curDistance;
            }
            visited.insert(curNode);
            for(auto cur : adjMap[curNode]){
                if(visited.count(cur.first) == 0){
                    q.push({(curDistance + cur.second), cur.first});
                }
            }
            
        }
        if(visited.size() != n){
            return -1;
        }
        return longest;
    }
};
