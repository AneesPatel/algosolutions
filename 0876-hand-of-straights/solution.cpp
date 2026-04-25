class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        unordered_map<int, int> counts;
        for(int cur : hand){
            counts[cur]++;
        }
        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); ++i){
            if(counts[hand[i]] > 0){
                for(int j = 0; j < groupSize; ++j){
                    if(counts[hand[i] + j] <= 0){
                        return false;
                    }
                    counts[hand[i] + j]--;
                }
            }
        }
        return true;
    }
};
