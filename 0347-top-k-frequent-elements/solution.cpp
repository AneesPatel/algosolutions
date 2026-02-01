class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> map = {};
        for (int i = 0; i < nums.size(); i++){
            if (map.count(nums[i])){
                map[nums[i]] += 1;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        for (auto i : map){
            q.push({i.second, i.first});
        }
        vector<int> res = {};
        while(res.size() != k){
            int temp = q.top().second;
            q.pop();
            res.push_back(temp);
        }
        return res;

    }
};
