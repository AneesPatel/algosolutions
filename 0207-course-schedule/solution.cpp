class Solution {
public:
    unordered_map<int, vector<int>> preqMap;
    //maps preq to a list of all courses that need that preq
    unordered_set<int> prevs;
    bool dfs(int curCourse){
        if(prevs.count(curCourse)){
            return false;
        }
        if(preqMap[curCourse].empty()){
            return true;
        }
        
        prevs.insert(curCourse);
        for(auto cur : preqMap[curCourse]){
            if(!dfs(cur)){
                return false;
            }
        }
        prevs.erase(curCourse);
        preqMap[curCourse].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //populate our preqMap
        for(int i = 0; i < numCourses; ++i){
            preqMap[i] = {};
        }
        for(auto cur : prerequisites){
            preqMap[cur[0]].push_back(cur[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }
};
