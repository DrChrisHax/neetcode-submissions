class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const auto& s : strs) {
            std::vector<int> count(26, 0);
            for (const char c : s) {
                ++count[c - 'a'];
            }

            std::string key = std::to_string(count[0]);
            for (std::size_t i = 1uz; i < 26uz; ++i) {
                key += ',' + count[i];
            }
            map[key].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        for (const auto& it : map) {
            res.push_back(it.second);
        }

        return res;
    }
};
