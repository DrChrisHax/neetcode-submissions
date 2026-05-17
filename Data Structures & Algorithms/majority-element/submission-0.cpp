class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int n = nums.size();
        if (n == 1) return nums[0];

        int res = nums[0];
        int count = 0;

        for (int i = 1; i < n; ++i) {
            int val = nums[i];
            if (val == res) {
                ++count;
            } else {
                --count;
                if (count < 0) {
                    res = val;
                    count = 0;
                }
            }
        }

        return res;
    }
};