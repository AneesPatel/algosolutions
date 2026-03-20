class Solution {
    void mossad(const string& node, unordered_map<string, vector<string>>& adjList, vector<string>& curComp, unordered_set<string>& visited) {
        visited.insert(node);
        curComp.push_back(node);
        for(const auto& nei : adjList[node]){
            if (visited.find(nei) == visited.end()){
                mossad(nei, adjList, curComp, visited); 
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> adjList{};
        unordered_map<string, string> emailToName{}; 
        unordered_set<string> visited{};
        vector<vector<string>> res{};

        for(const auto& account : accounts) {
            const string& name{account[0]};
            const string& firstEmail{account[1]}; 
            for (int i{1}; i < account.size(); ++i) {
                const string& email{account[i]};
                emailToName[email] = name; 
                if (i > 1){
                    adjList[firstEmail].push_back(email);
                    adjList[email].push_back(firstEmail);
                }
            }
        }
        for(auto const& [email, name] : emailToName){
            if(visited.find(email) == visited.end()) {
                vector<string> curComp;
                mossad(email, adjList, curComp, visited);
                sort(curComp.begin(), curComp.end());
                curComp.insert(curComp.begin(), name);
                res.push_back(curComp);
            }
        }
        return res;
    }
};
