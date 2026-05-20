class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        struct PairHash {
            size_t operator()(const pair<int,int>& p) const {
                return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
            }
        };

        unordered_set<pair<int,int>, PairHash> obstacleSet;
        for (auto& o : obstacles)
            obstacleSet.insert({o[0], o[1]});

        // N, E, S, W
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0; // start facing North
        int x = 0, y = 0, maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -2)      dir = (dir + 3) % 4; // turn left
            else if (cmd == -1) dir = (dir + 1) % 4; // turn right
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obstacleSet.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
