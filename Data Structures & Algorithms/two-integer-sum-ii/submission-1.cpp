class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int val = numbers[l] + numbers[r] - target;

            if (val > 0) {
                --r;
            } else if (val < 0) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {-1, -1};
    }
};
