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
    void dfs(TreeNode* node, int prevMax, int& res){
        if (not node) return;
        if (node->val >= prevMax){
            res++;
            prevMax = node->val;
        }
        dfs(node->left, prevMax, res);
        dfs(node->right, prevMax, res);

    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;    
    }
};
