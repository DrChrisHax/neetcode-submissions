class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::size_t n = nums.size();
        std::vector<int> res(n, 1);

        for (std::size_t i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (std::size_t i = n; i > 0; --i) {
            res[i - 1] *= postfix;
            postfix *= nums[i - 1];
        }

        return res;
    }
};
