class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int lowest = r;
        while (l <= r){
            int speed = (l + r) / 2;
            long long curtimes = 0;
            for(int cur:piles){
                curtimes += ceil(static_cast<double>(cur) / speed);
            }
            if (curtimes <= h){
                lowest = speed;
                r = speed - 1;
            }
            else{
                l = speed + 1;
            }
        }
        return lowest;
    }
};
