class TrieNode{
    public:
    vector<TrieNode*> nei;
    bool isWord;
    TrieNode(){
        nei = vector<TrieNode*>(26, nullptr);
        isWord = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(node, 0, word);
    }
    bool dfs(TrieNode* node, int index, string& word){
        if(index >= word.size()){
            return node->isWord;
        }
        bool res = false;
        if(word[index] == '.'){
            for(int i = 0; i < 26; ++i){
                if(node->nei[i] != nullptr and dfs(node->nei[i], index + 1, word)){
                    return true;
                }
            }
        }else{
            if(node->nei[word[index] - 'a'] != nullptr){
                return dfs(node->nei[word[index] - 'a'], index + 1, word);
            }
        }
        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
