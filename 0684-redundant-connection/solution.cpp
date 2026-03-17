class Solution {
public:
    int find(int node, vector<int>& parents){
        if(node != parents[node]){
            parents[node] = find(parents[node], parents);
        }
        return parents[node];
    }
    bool unionFind(int node1, int node2, vector<int>& parents){
        int root1 = find(node1, parents);
        int root2 = find(node2, parents);
        if(root1 == root2){
            return false;
        }
        parents[root1] = root2;

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents;
        for(int i = 0; i < n + 1; ++i){
            parents.push_back(i);
        }
        for(auto curPair : edges){
            if(!unionFind(curPair[0], curPair[1], parents)){
                return (curPair);
            }
        }
        return {};
    }
};
