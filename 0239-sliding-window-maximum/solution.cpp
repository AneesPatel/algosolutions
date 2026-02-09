class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        deque <int> q;
        vector<int> res(nums.size() - k + 1);
        while (r < nums.size()){
            while(!q.empty() and nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(l > q.front()){
                q.pop_front();
            }

            if (r + 1 >= k){
                res[l] = (nums[q.front()]);
                l++;
            }
            r++;

        }

        return res;
    }
};
