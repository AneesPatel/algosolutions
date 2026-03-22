class Solution {
public:
    void dfs(string cur, vector<string>& res, unordered_map<string, deque<string>>& adj){
        while(!adj[cur].empty()){
            string temp = adj[cur].back();
            adj[cur].pop_back();  
            dfs(temp, res, adj);
        }
        res.push_back(cur);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        vector<string> res;
        for(auto cur : tickets){
            adj[cur[0]].push_back(cur[1]);
        }
        for(auto& [key, q] : adj){
            sort(q.begin(), q.end(), greater<string>());
        }
        dfs("JFK", res, adj);
        reverse(res.begin(), res.end());
        return res;
    }
};
