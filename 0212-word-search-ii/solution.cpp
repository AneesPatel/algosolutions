class TrieNode{
    public:
        vector<TrieNode*> nei;
        bool isWord;
        int wordIndex;
        TrieNode(){
            nei = vector<TrieNode*>(26, nullptr);
            isWord = false;
            wordIndex = 0;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
    void addWord(string word, int i){
        TrieNode* node = root;
        for(char& cur : word){
            int index = cur - 'a';
            if(node->nei[index] == nullptr){
                node->nei[index] = new TrieNode();
            }
            node = node->nei[index];
        }
        node->isWord = true;
        node->wordIndex = i;
    }
};
class Solution {
public:
    int ROW; int COL;
    void dfs(int r, int c, TrieNode* node, vector<vector<char>>& board, vector<string>& res, vector<string>& words){
        if(node->isWord == true){
            res.push_back(words[node->wordIndex]);
            node->isWord = false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        static const vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for(const auto& dire : directions){
            int nr = r + dire[0];
            int nc = c + dire[1];
            if(nr < 0 or nc < 0 or nr >= ROW or nc >= COL or board[nr][nc] == '#'){
                continue;
            }
            int index = board[nr][nc] - 'a';
            if(node->nei[index] != nullptr){
                dfs(nr, nc, node->nei[index], board, res, words);
            }
        }
        board[r][c] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for(int i = 0; i < words.size(); ++i){
            string word = words[i];
            trie-> addWord(word, i);
        }
        vector<string> res;
        ROW = board.size();
        COL = board[0].size();
        for(int r = 0; r  < ROW; ++r){
            for(int c = 0; c < COL; ++c){
                int index = board[r][c] - 'a';
                if(trie->root->nei[index] != nullptr){
                    dfs(r, c, trie->root->nei[index], board, res, words);
                }
            }
        }
        return res;
    }
};
