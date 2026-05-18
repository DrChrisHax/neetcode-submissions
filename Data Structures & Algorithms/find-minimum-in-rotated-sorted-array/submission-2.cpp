class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        int res = nums[0];

        while (l <= r) {
            int n_l = nums[l];
            int n_r = nums[r];

            if (n_l < n_r) {
                res = std::min(res, n_l);
                break;
            }

            int mid = l + (r - l) / 2;
            int n_m = nums[mid];
            res = std::min(res, n_m);

            if (n_m >= n_l) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
