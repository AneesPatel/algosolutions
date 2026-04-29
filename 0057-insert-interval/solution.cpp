class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool ins = false;
        for(auto cur : intervals){
            if(ins == true){
                res.push_back(cur);
                continue;
            }
            //3cases: 1 = newinterval < cur; 2 = new interval > cur; 3 = intersecting so merge
            if(newInterval[1] < cur[0]){
                if(!ins){
                    ins = true;
                    res.push_back(newInterval);
                }
                res.push_back(cur);
            }else if(newInterval[0] > cur[1]){
                res.push_back(cur);
            }
            else{
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max(newInterval[1], cur[1]);
            }
        }
        if(!ins){
            res.push_back(newInterval);
        }
        return res;
    }
};
