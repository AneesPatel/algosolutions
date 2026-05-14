class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        double res = 1;
        long power = abs((long)n);
        while(power){
            if(power & 1){
                res *= x;
            }
            x *= x;
            power = power >> 1;
        }
        if(n < 0){
            return 1 / res;
        }
        return res;
    }
};
