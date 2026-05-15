class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> counts; //(map of x : map y : count) ; for o(1) lookkup
    DetectSquares() {
        counts = {};
    }
    
    void add(vector<int> point) {
        counts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        vector<vector<int>> potxs;
        vector<vector<int>> potys;
        int x = point[0];
        int y = point[1];

        int res = 0;
        for(auto& [curx, curymap] : counts){
            for(auto& [cury, count] : curymap){
                if(curx == x){
                potxs.push_back(vector<int>{curx, cury});
                }
                if(cury == y){
                    potys.push_back(vector<int>{curx, cury});
                }
            }
            
        }
        for(vector<int>& curxpair : potxs){
            for(vector<int>& curypair : potys){
                if(counts.count(curypair[0]) > 0 and counts[curypair[0]].count(curxpair[1]) > 0){
                    if(counts[curypair[0]][curxpair[1]] > 0 and abs(curypair[0] - x) == abs(curxpair[1] - y) and (curypair[0] != x) and (curxpair[1] != y)){
                        res += counts[curypair[0]][curxpair[1]] * counts[curxpair[0]][curxpair[1]] * counts[curypair[0]][curypair[1]]; 
                    }
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
