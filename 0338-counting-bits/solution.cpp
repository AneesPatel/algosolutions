class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int count = 0;
        for(int i = 0; i <= n; ++i){
            count = 0;
            int v = i;
            for(int j = 0; j < 32; ++j){
                if(v & 1){
                    count++;
                }
                v = v >> 1;
            }
            res.push_back(count);
        }
        return res;
    }
};
