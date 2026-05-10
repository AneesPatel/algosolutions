class Solution {
public:
    bool dfs(int n, unordered_set<int>& prevs){
        if(n == 1){
            return true;
        }
        
        int total = 0;
        while(n > 0){
            total += (n % 10) * (n % 10);
            n = n/10;
        }
        
        if(prevs.count(total)){
            return false;
        }
        prevs.insert(total);
        return dfs(total, prevs);
    }
    bool isHappy(int n) {
        unordered_set<int> prevs;
        return dfs(n, prevs);
    }
};
