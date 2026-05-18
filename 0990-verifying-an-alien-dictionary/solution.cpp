class Solution {
public:
    bool check(string& word1, string& word2, string order, unordered_map<char, int>& ranks){
        if(word1 == word2){
            return true;
        }
        for(int i = 0; i < min(word1.size(), word2.size()); ++i){
            if(ranks[word1[i]] < ranks[word2[i]]){
                return true;
            }
            else if(ranks[word1[i]] > ranks[word2[i]]){
                return false;
            }
        }
        if(word1.size() < word2.size()){
            return true;
        }
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1){
            return true;
        }
        unordered_map<char, int> ranks;
        for(int i = 0; i < order.size(); ++i){
            ranks[order[i]] = i;
        }

        for(int i = 1; i < words.size(); ++i){
            if(not check(words[i - 1], words[i], order, ranks)){
                return false;
            }
        }
        return true;
    }
};
