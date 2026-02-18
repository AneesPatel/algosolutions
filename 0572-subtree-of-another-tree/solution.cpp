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
    bool isSameTree(TreeNode* node1, TreeNode* node2){
        if(not node1 and not node2){
            return true;
        }
        if (!node1 or !node2){
            return false;
        } 
        
        if (node1->val != node2->val){
            return false;
        }
        return(isSameTree(node1->left, node2->left) and isSameTree(node1->right, node2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (not subRoot and root) return false;
        if (not root and subRoot) return false;
        if(root->val == subRoot->val){
            if(isSameTree(root, subRoot)){
                return true;
            }
        }
        return(isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
    }
};
