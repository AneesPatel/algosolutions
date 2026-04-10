#define MAX_NUM 101
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int indexMap[MAX_NUM*3] = {0};   // Stores up to 3 indices for each number
        int count[MAX_NUM] = {0};      // Count occurrences of each number
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            int idx = nums[i] * 3 + (count[nums[i]] % 3);
            indexMap[idx] = i;

            // When a number appears 3 or more times
            if (count[nums[i]] >= 3) {
                int base = nums[i] * 3;
                int a = indexMap[base];
                int b = indexMap[base + 1];
                int c = indexMap[base + 2];

                int totalDist = abs(a - b) + abs(b - c) + abs(a - c);
                res = min(res, totalDist);
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};


