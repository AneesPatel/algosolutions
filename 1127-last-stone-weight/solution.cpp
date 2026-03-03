class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()){
            return 0;
        }
        if (stones.size() == 1){
            return stones[0];
        }
        priority_queue<int> maxq;
        for(int stone : stones){
            maxq.push(stone);
        }
        int prev;
        while(maxq.size() > 1){
            prev = maxq.top();
            maxq.pop();
            prev = abs(prev - maxq.top());
            maxq.pop();
            if(prev > 0){
                maxq.push(prev);
            }
            
        }
        if(maxq.empty()){
            return 0;
        }
        return maxq.top();


    }
};
