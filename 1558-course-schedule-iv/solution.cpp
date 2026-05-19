class Solution {
public:
    bool dfs(int goal, int curNode, unordered_map<int, vector<int>>& preqmap, vector<bool>& visited){
        if(goal == curNode){
            return true;
        }
        if(visited[curNode]){
            return false;
        }
        visited[curNode] = true;
        for(auto& curpreq : preqmap[curNode]){
            if (dfs(goal, curpreq, preqmap, visited)){
                return true;
            }
        }

        return false;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //build a graph of preq, starting from each query traverse until we find preq, if found we continue else we return false;
        unordered_map<int, vector<int>> preqmap;
        for(vector<int>& cur : prerequisites){
            preqmap[cur[1]].push_back(cur[0]);
        }
        unordered_set<int> prevs;
        vector<bool> res;
        for(auto& cur : queries){
            vector<bool> visited(numCourses, false);
            res.push_back(dfs(cur[0], cur[1], preqmap, visited));
        }
        return res;
    }
};
