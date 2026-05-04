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
            int index = cur - 'a';
            if(node->nei[index] == nullptr){
                node->nei[index] = new TrieNode();
            }
            node = node->nei[index];
        }
        node->isWord = true;
        node->wordIndex = index;
    }
    bool search(string word){
        TrieNode* node = root;
        for(char& cur : word){
            int index = cur - 'a';
            if(node->nei[index] == nullptr){
                return false;
            }
            node = node->nei[index];
        }
        return node->isWord;
    }
    bool prefix(string word){
        TrieNode* node = root;
        for(char& cur : word){
            int index = cur - 'a';
            if(node->nei[index] == nullptr){
                return false;
            }
            node = node->nei[index];
        }
        return true;

    }
};
class Solution {
public:
    int ROW;
    int COL;
    void dfs(int r, int c, TrieNode* node, vector<string>& res, vector<vector<char>>& board, vector<string>& words){
        if(node->isWord == true) {
            res.push_back(words[node->wordIndex]);
            node->isWord = false; 
            
        }
        char temp = board[r][c];
        board[r][c] = '#';
        const static int dire[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for(const auto& curdir : dire){
            int nr = r + curdir[0];
            int nc = c + curdir[1];
            if(nr >= 0 and nc >= 0 and nr < ROW and nc < COL and board[nr][nc] != '#' and node->nei[board[nr][nc] - 'a'] != nullptr){
                dfs(nr, nc, node->nei[board[nr][nc] - 'a'], res, board, words);
            }
        }
        board[r][c] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* trie = new Trie(); 
        for(int i = 0; i < words.size(); ++i){
            trie->addWord(words[i], i);
        }
        ROW = board.size();
        COL = board[0].size();
        
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
