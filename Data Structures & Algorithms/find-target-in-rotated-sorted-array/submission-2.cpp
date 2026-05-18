class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int pivot = l;

        int res = binarySearch(nums, target, 0, pivot - 1);
        if (res != -1) return res;

        return binarySearch(nums, target, pivot, n - 1);

    }

    int binarySearch(std::vector<int>& nums, int target, int l, int r) {
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
