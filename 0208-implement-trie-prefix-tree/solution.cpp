class TrieNode{
public:
    vector<TrieNode*> nei;
    bool isWord;
    TrieNode() {
        nei = vector<TrieNode*>(26, nullptr); 
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(const char& cur : word){
            if(node->nei[cur - 'a'] == nullptr){
                node->nei[cur - 'a'] = new TrieNode();
            }
            node = node->nei[cur - 'a'];
        }
        node->isWord = true;

    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(const char& cur : word){
            auto convert = cur - 'a';
            if(node->nei[convert] != nullptr){
                node = node->nei[convert];
            }
            else{
                return false;
            }
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(const char& cur : prefix){
            auto convert = cur - 'a';
            if(node->nei[convert] != nullptr){
                node = node->nei[convert];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
