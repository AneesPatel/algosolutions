class Solution {
public:
    int maxArea(vector<int>& height) {
        // 1. This is the magic block that makes it faster than 99% of submissions
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int l = 0;
        int r = height.size() - 1;
        int maxWater = 0;
        
        while (l < r) {
            // 2. Pre-calculate min height to avoid calling height[...] multiple times
            int h = min(height[l], height[r]);
            
            // 3. Your manual 'if' check is actually great, keep it!
            int curArea = (r - l) * h;
            if (curArea > maxWater) maxWater = curArea;

            // 4. Skip lines that are shorter than the current height 'h'
            // This is the algorithmic speedup.
            while (l < r && height[l] <= h) l++;
            while (l < r && height[r] <= h) r--;
        }
        return maxWater;
    }
};
