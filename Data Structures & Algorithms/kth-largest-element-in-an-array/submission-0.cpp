class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::partial_sort(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>());
        return nums[k - 1]; 
    }
};
