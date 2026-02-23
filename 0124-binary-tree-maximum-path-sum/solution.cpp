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
    int res;
    int dfs(TreeNode* node){
        if (not node){
            return 0;
        }
        int leftmax = max(dfs(node->left), 0);
        int rightmax = max(dfs(node->right), 0);
        //path where we split
        res = max(res, leftmax + rightmax + node->val);
        //path where we do NOT split I.E. continue with largest path;
        return (node->val + max(leftmax, rightmax));

    }
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res; 
    }
};
