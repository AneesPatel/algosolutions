/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    void serialDfs(TreeNode* node){
        if (not node){
            res += "N,";
            return;
        }
        res += to_string(node->val) + ",";
        serialDfs(node->left);
        serialDfs(node->right);

    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res = "";
        serialDfs(root);
        return res;
    }
    int index;
    TreeNode* dfs(const string& data){
        if (index >= data.size()) return nullptr;
        size_t comIndex = data.find(',', index);
        string substring = data.substr(index, comIndex - index);
        index = comIndex + 1;
        if (substring == "N"){
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(stoi(substring + ""));
        newNode->left = dfs(data);
        newNode->right = dfs(data);
        return newNode;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        index = 0;
        return dfs(data);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
