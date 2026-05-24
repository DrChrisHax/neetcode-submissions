class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        std::size_t size = nums1.size() + nums2.size();
        std::size_t mid = (size + 1) / 2;

        if (nums2.size() < nums1.size()) {
            std::swap(nums1, nums2);
        }

        int l = 0, r = nums1.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = mid - i;

            int l1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int r1 = i < nums1.size() ? nums1[i] : INT_MAX;
            int l2 = j > 0 ? nums2[j - 1] : INT_MIN;
            int r2 = j < nums2.size() ? nums2[j] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (size % 2 != 0) {
                    return std::max(l1, l2);
                }
                return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};