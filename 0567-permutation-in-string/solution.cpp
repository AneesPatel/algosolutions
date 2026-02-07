class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        unordered_map<char, int> count = {};
        unordered_map<char, int> count2 = {};
        for(char cur:s1){
            count[cur] += 1;
        }
        int l = 0;
        for (int r = 0; r < s2.size(); r++){
            count2[s2[r]] += 1;
            while (r - l + 1 > n){
                count2[s2[l]] -= 1;
                if (count2[s2[l]] == 0) {
                    count2.erase(s2[l]);
                }
                l += 1;
            }
            if (count == count2){
                return true;
            }

        }
        return false;
    }
};
