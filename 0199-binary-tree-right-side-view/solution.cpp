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
private:
    vector<int> res = {}; 
public:
    void dfs(TreeNode* node, int count){
        if (not node) return;
        if(res.size() == count){
            res.push_back(node->val);
        }
        else{
            res[count] = node->val;
        }
        dfs(node->left, count + 1);
        dfs(node->right, count + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
