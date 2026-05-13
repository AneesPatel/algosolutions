class Solution {
public:
    bool dfs(int n, std::unordered_set<int>& prevs){
        if(n == 1){
            return true;
        }
        if(prevs.count(n)){
            return false;
        }
        prevs.insert(n);
        int res = 0;
        while(n > 0){
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return dfs(res, prevs);
    }
    bool isHappy(int n) {
        std::unordered_set<int> prevs;
        return dfs(n, prevs);
    }    
};
