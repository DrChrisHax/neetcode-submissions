class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map; // num, index

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int val = target - num;

            auto it = map.find(val);
            if (it != map.end()) {
                return {it->second, i};
            } else {
                map[num] = i;
            }
        }

        return {};
    }
};
