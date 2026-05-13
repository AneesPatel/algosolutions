class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1] += 1;
        int carry = 0;
        for(int i = n - 1; i >= 0; --i){
            digits[i] += carry;
            if(digits[i] < 10){
                return digits;
            }
            digits[i] -= 10;
            carry = 1;
        }
        if(carry > 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
