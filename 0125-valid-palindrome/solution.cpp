#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r){
            while(l < r and not isalnum(s[l])){
                l++;
            }
            while(l < r and not isalnum(s[r])){
                r--;
            }
            if (std::tolower(s[l]) != std::tolower(s[r])){
                return false;
            }
            else{
                r--;
                l++;
            }
        }
        return true;
    }
};
