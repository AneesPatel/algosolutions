class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res(3, 0);
        for(const auto& cur : triplets){
            if(cur[0] > target[0] or cur[1] > target[1] or cur[2] > target[2]){
                continue;
            }
            res[0] = max(cur[0], res[0]);
            res[1] = max(cur[1], res[1]);
            res[2] = max(cur[2], res[2]);

        }
        return (res == target);
    }
};
