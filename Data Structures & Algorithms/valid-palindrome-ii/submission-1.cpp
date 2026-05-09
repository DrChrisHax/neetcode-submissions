class Solution {
public:
    bool validPalindrome(const string& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return isPalin(s, l + 1, r) || isPalin(s, l, r - 1);
            }
            ++l;
            --r;
        }
        return true;
    }

private:
    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

};