class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;

        for (auto n : nums) {
            s.insert(n);
        }

        return s.size() != nums.size();

    }
};