class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int val = nums[mid];

            if (val > target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
