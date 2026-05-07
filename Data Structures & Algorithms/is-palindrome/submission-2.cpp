class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty()) return true;
        std::size_t l = 0uz, r = s.size() - 1uz;

        while (l < r) {
            
            while (l < r && !std::isalnum(static_cast<unsigned char>(s[l]))) ++l;

            while (r > l && !std::isalnum(static_cast<unsigned char>(s[r]))) --r;

            if (std::tolower(static_cast<unsigned char>(s[l])) != std::tolower(static_cast<unsigned char>(s[r]))) {
                return std::isalnum(static_cast<unsigned char>(s[l])) == std::isalnum(static_cast<unsigned char>(s[r])) ? false : true;
            }

            if (l < r) {
                ++l;
                --r;
            }
        }

        return true;
    }
};