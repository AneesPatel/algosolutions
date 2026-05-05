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
        void addWord(string word, int index){
            TrieNode* node = root;
            for(char& cur : word){
                int i = cur - 'a';
                if(node->nei[i] == nullptr){
                    node->nei[i] = new TrieNode();
                }
                node = node->nei[i];
            }
            node->isWord = true;
            node->wordIndex = index;
        }
};
class Solution {
public:
    int ROW;
    int COL;
    void dfs(int r, int c, TrieNode* node, vector<string>& res, vector<vector<char>>& board, vector<string>& words){
        if(node->isWord == true){
            res.push_back(words[node->wordIndex]);
            node->isWord = false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        static const vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto& dire : directions){
            int nr = r + dire[0];
            int nc = c + dire[1];
            if(nr >= ROW or nc >= COL or nr < 0 or nc < 0 or board[nr][nc] == '#'){
                continue;
            }

            if(node->nei[board[nr][nc] - 'a'] != nullptr){
                dfs(nr, nc, node->nei[board[nr][nc] - 'a'], res, board, words);
            }
        }
        board[r][c] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        ROW = board.size();
        COL = board[0].size();

        Trie* trie = new Trie();

        for(int i = 0; i < words.size(); ++i){
            trie->addWord(words[i], i);
        }
        for(int r = 0; r < ROW; ++r){
            for(int c = 0; c < COL; ++c){
                int index = board[r][c] - 'a';
                if(trie->root->nei[index] != nullptr){
                    dfs(r, c, trie->root->nei[index], res, board, words);
                }
            }
        }
        return res;

    }
};
