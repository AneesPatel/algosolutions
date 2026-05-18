class Solution {
public:
    int count;
    bool valid(int l, int r, string& s){
        if(l > r){
            return true;
        }
        if(s[l] != s[r] and count == 1){
            return false;
        }
        else if(s[l] != s[r]){
            count++;
            return valid(l + 1, r, s) or valid(l, r - 1, s);
        }

        return valid(l + 1, r - 1, s);
    }
    bool validPalindrome(string s) {
        count = 0;
        return valid(0, s.size() - 1, s);
    }
};
