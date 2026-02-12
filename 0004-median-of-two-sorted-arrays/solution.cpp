class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        int l = 0; int r = nums1.size();
        while (true){
            int mid = (l + r) / 2;
            int mid2 = half - mid;
            
            int shortleft = INT_MIN; int shortright = INT_MAX;
            int longleft = INT_MIN; int longright = INT_MAX;

            if (mid - 1 >= 0){
                shortleft = nums1[mid - 1];
            }
            if (mid2 - 1 >= 0){
                longleft = nums2[mid2 - 1];
            }

            if (mid < nums1.size()){
                shortright = nums1[mid];
            }

            if (mid2 < nums2.size()){
                longright = nums2[mid2];
            }

            if((shortleft <= longright) and (longleft <= shortright)){
                if (total % 2 == 0){
                    return(((max(shortleft, longleft) + min(shortright, longright))) / 2.0);
                }else{
                    return(min(shortright, longright));
                }
            }
            else if(shortleft > longright){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }

        }
    }
};
