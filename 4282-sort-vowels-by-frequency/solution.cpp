class Solution {
public:
    bool isVowel(char c){
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> first_ooc;
        vector<int> vowel_indices;
        vector<char> vowels;
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(isVowel(c)){
                vowels.push_back(c);
                vowel_indices.push_back(i);
                freq[c]++;
                if(first_ooc.find(c) == first_ooc.end()){
                    first_ooc[c] = i;
                }
            }
        }
        sort(vowels.begin(), vowels.end(), [&](char a, char b){
            if(freq[a] != freq[b]){
                return freq[a] > freq[b];
            }
            return first_ooc[a] < first_ooc[b];
        });
        for(int i = 0; i < vowels.size(); ++i){
            s[vowel_indices[i]] = vowels[i];
        }
        return s;
    }
};
