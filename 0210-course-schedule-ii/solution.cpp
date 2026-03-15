class Solution {
public:
    unordered_set<int> prevsCycle;
    unordered_set<int> prevsRes;
    bool dfs(int cur, vector<int>& res, unordered_map<int, vector<int>>& adjMap){
        if(prevsCycle.count(cur)){
            return false;
        }
        if(prevsRes.count(cur)){
            return true;
        }

        prevsCycle.insert(cur);
        for(auto curAdj : adjMap[cur]){
            if(!dfs(curAdj, res, adjMap)){
                return false;
            }
        }
        prevsCycle.clear();
        prevsRes.insert(cur);
        res.push_back(cur);

        return true;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        prevsCycle.clear();
        prevsRes.clear();
        unordered_map<int, vector<int>> adjMap;
        for(int i = 0; i < numCourses; ++i){
            adjMap[i] = {};
        }
        for(const auto& curPre : prerequisites){
            adjMap[curPre[0]].push_back(curPre[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i, res, adjMap)){
                return {};
            }
        }
        return res;

    }
};
