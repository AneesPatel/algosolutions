class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string temp = to_string(n);
        reverse(temp.begin(), temp.end());
        int newn = stoi(temp);
        int res = 0;
        int start = min(n, newn);
        int end = max(n, newn);
        
        for(int i = start; i <= end; ++i){
            if(isPrime(i)){
                res += i;
            }
        }

        return res;
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
    
    return true;
}
};
