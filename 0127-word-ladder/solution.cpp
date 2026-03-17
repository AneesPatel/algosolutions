class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string cur;
        int count = 0;
        unordered_map<string, vector<string>> possibleWords;
        // string word with one char replaced with "*" to words that have that string
        for(string word : wordList){
            for(int i = 0; i < word.size(); ++i){
                string temp = word.substr(0, i) + "*" + word.substr(i + 1);
                possibleWords[temp].push_back(word);
            }
        }
        queue<pair<int, string>> q;
        //count, curWord
        q.push({1, beginWord});
        while(!q.empty()){
            auto curPair = q.front();
            count = curPair.first;
            cur = curPair.second;
            q.pop();
            if(cur == endWord){
                return count;
            }
            for(int i = 0; i < cur.size(); ++i){
                string temp1 = cur.substr(0, i) + "*" + cur.substr(i + 1);
                for(string posWord : possibleWords[temp1]){
                    q.push({count + 1, posWord});
                }
                possibleWords.erase(temp1);
            }
        }
        return 0;
    }
};
