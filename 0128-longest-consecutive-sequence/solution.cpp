class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int longest = 0;
        unordered_set<int> map(nums.begin(), nums.end());
        for (int cur:map){
            if (map.find(cur - 1) == map.end()){
                int count = 1;
                int temp = cur;
                while(map.count(temp + 1)){
                    count += 1;
                    temp += 1;
                } 
                longest = max(count, longest);
            }
        }
        return longest;

    }
};
