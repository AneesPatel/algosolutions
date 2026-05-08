class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        int MSB = 1;
        for(int i = 1; i <= n; ++i){
            if(MSB * 2 == i){
                MSB = i;
            }
            res[i] = 1 + res[i - MSB];
            
        }
        return res;
    }
};
