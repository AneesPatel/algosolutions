class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);
        if(totalgas < totalcost){
            return -1;
        }

        int cur = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); ++i){
            cur += gas[i] - cost[i];
            if(cur < 0){
                cur = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
