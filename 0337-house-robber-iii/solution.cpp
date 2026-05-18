/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> memobuy;
    unordered_map<TreeNode*, int> memoskip;

    int dfs(bool state, TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        if(state == true and memobuy.count(node)){
            return memobuy[node];
        }
        if(state == false and memoskip.count(node)){
            return memoskip[node];
        }
        int skipmax = 0;
        int buymax = 0;
        if(state == true){
            skipmax = dfs(true, node->left) + dfs(true, node->right);
            buymax = node->val + dfs(false, node->right) + dfs(false, node->left);
        }
        else{
            skipmax = dfs(true, node->left) + dfs(true, node->right);
        }
        if(state == true){
            memobuy[node] = max(skipmax, buymax);
        } else{
            memoskip[node] = skipmax;
        }
        return max(skipmax, buymax);
    }
    int rob(TreeNode* root) {
        //track state and whethor or not we have bought; check max of boths p
        //true = able to steal, false = unable to steal; total;

        return max(dfs(true, root), dfs(false, root));
    }
};
