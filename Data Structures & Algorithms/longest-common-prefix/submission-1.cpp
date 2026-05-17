class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        std::string prefix{};

        for (int i = 0; i < strs[0].size(); ++i) {
            char new_char = strs[0][i];
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != new_char) {
                    return prefix;
                }
            }
            prefix.push_back(new_char);
        }
        return prefix;
    }
};