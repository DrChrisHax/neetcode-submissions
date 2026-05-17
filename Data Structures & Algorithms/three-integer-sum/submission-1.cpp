class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (val > 0) break;
            if (i > 0 && val == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int threeSum = val + nums[l] + nums[r];
                if (threeSum > 0) {
                    --r;
                } else if (threeSum < 0) {
                    ++l;
                } else {
                    res.push_back({nums[l], nums[r], val});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
            }
        }
        return res;
    }
};
