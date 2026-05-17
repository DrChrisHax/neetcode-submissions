class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        int res = 0;

        for (auto num : nums) {
            if (hashMap[num]) continue;

            hashMap[num] = hashMap[num - 1] + hashMap[num + 1] + 1;
            hashMap[num - hashMap[num - 1]] = hashMap[num];
            hashMap[num + hashMap[num + 1]] = hashMap[num];
            res = std::max(res, hashMap[num]);
        }

        return res;
    }
};
