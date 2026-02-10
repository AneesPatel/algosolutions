class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int lowest = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2;
            if (lowest > nums[mid]){
                lowest = nums[mid];
            }
            if (nums[r] > nums[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return lowest;
    }
};
