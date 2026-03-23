class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        //(prevmax, r, c)
        int n = grid.size();
        vector<vector<int>> directions = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        unordered_set<int> visited;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int prevMax = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if(visited.count(grid[r][c])){
                continue;
            }
            visited.insert(grid[r][c]);
            if(prevMax < grid[r][c]){
                prevMax = grid[r][c];
            }
            if(r == n - 1 and c == n -1){
                return prevMax;
            }
            for(const auto& dire : directions){
                int nr = r + dire[0];
                int nc = c + dire[1];
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and visited.count(grid[nr][nc]) == 0){
                    pq.push({max(grid[nr][nc], prevMax), nr, nc});
                }
            }
        }
        return -1;
    }
};
