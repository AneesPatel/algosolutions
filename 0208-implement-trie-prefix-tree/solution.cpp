class TrieNode{
    public:
        vector<TrieNode*> nei;
        bool isWord;
        TrieNode(){
            nei = vector<TrieNode*>(26, nullptr);
            isWord = false;
        }

};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(const char& cur : word){
            int index = cur - 'a';
            if(node->nei[index] == nullptr){
                node->nei[index] = new TrieNode();
            }
            node = node->nei[index];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(const char& cur : word){
            int index = cur - 'a'; 
            if(node->nei[index] == nullptr){
                return false;
            }
            node = node->nei[index];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(const char& cur : prefix){
            int index = cur - 'a'; 
            if(node->nei[index] == nullptr){
                return false;
            }
            node = node->nei[index];
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
