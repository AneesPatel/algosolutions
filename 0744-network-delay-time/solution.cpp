#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Use vector instead of unordered_map for the adjacency list (1-indexed)
        vector<vector<pair<int, int>>> adjList(n + 1);
        for(const auto& edge : times){
            // edge[0] = source, edge[1] = target, edge[2] = weight
            adjList[edge[0]].push_back({edge[2], edge[1]}); 
        }

        vector<int> distMap(n + 1, INT_MAX);
        distMap[k] = 0; // Initialize starting node's distance to 0

        // Min-heap: stores {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        while(!q.empty()){
            int curDistance = q.top().first;
            int curNode = q.top().second;
            q.pop();

            // Lazy deletion: skip if we've already found a shorter path to curNode
            if(curDistance > distMap[curNode]){
                continue;
            }

            // 2. Iterate by reference to avoid copying
            for(const auto& neighbor : adjList[curNode]){
                int weight = neighbor.first;
                int nextNode = neighbor.second;
                int newDist = curDistance + weight;

                // 3. Pruning: Only push to PQ if we actually found a strictly shorter path
                if(newDist < distMap[nextNode]){
                    distMap[nextNode] = newDist;
                    q.push({newDist, nextNode});
                }
            }
        }

        int res = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(distMap[i] == INT_MAX){
                return -1; // A node is unreachable
            }
            res = max(res, distMap[i]);
        }

        return res;
    }
};
