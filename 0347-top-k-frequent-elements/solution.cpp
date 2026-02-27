class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> count;
        for(auto cur: nums){   
            count[cur] += 1;
        }
        pair<int, int> temp;
        for(auto x: count){
            temp = {x.second, x.first};
            q.push(temp);
        }
        int i = 0;
        vector<int> res;
        while(i < k){
            res.push_back(q.top().second);
            q.pop();
            i++;
        }
        return res;
    }
};
