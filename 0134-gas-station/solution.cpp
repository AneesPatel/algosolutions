class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int res = 0;
        int totalgas = 0;
        int totalcost = 0;
        for(int i = 0; i < gas.size(); i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if(totalgas < totalcost){
            return -1;
        }
        for(int i = 0; i < gas.size(); ++i){
            cur = cur + gas[i] - cost[i];
            if(cur < 0){
                cur = 0;
                res = i + 1;
            }
        }
        if(res == gas.size()){
            return - 1;
        }
        return res;
    }
};
