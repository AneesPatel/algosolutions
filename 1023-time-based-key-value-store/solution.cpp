class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timemap = {};
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timemap.find(key) == timemap.end()){
            return "";
        }
        vector<pair<int, string>>& cur = timemap[key];
        int l = 0; int r = cur.size() - 1;
        string valid = "";
        while(l <= r){
            int mid = (l + r) / 2;
            if (cur[mid].first == timestamp){
                return cur[mid].second;
            }
            if (cur[mid].first < timestamp){
                valid = cur[mid].second;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return valid;
    }
};


