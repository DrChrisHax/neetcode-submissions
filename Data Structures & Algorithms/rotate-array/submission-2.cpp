class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = k % nums.size();
        std::rotate(nums.begin(), nums.end() - r, nums.end());
    }
};