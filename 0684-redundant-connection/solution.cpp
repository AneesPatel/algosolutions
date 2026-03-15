class Solution {
public:
    bool dfs(int cur, int findNode, unordered_set<int>& prevs, unordered_map<int, vector<int>>& adjMap){
        if(prevs.count(cur)){
            return false;
        }
        if(cur == findNode){
            return true;
        }
        prevs.insert(cur);
        for(auto curAdj : adjMap[cur]){
            if (dfs(curAdj, findNode, prevs, adjMap)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> prevs;
        unordered_map<int, vector<int>> adjMap;
        for(auto curPair : edges){
            //if starting at curpair 0 we can find curPair 1 it is a redundant
            prevs.clear();
            if (dfs(curPair[0], curPair[1], prevs, adjMap)){
                return curPair;
            }
            adjMap[curPair[0]].push_back(curPair[1]);
            adjMap[curPair[1]].push_back(curPair[0]);
            
        }
        return {};
        
    }
};
