class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for(auto cur : tasks){
            map[cur] += 1;
        }
        priority_queue<int> pq;
        for(auto cur : map){
            pq.push(cur.second);
        }
        int time = 0;
        queue<pair<int, int>> remaining; //freq pair to avaliable time
        int freq;
        while(!remaining.empty() || !pq.empty()){
            time += 1;
            if(!pq.empty()){
                freq = pq.top() - 1;
                pq.pop();
                if(freq > 0){
                    remaining.push({freq, time + n});
                }
            }
            if(!remaining.empty() and remaining.front().second <= time){
                pq.push(remaining.front().first);
                remaining.pop();
            }
        }
        return time;
    }
};
