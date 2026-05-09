class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string res;

        int p1 = 0, p2 = 0;
        int w1 = word1.size(), w2 = word2.size();

        while (p1 < w1 && p2 < w2) {
            res.push_back(word1[p1]);
            res.push_back(word2[p2]);
            ++p1;
            ++p2;
        }

        while (p1 < w1) {
            res.push_back(word1[p1]);
            ++p1;
        }

        while (p2 < w2) {
            res.push_back(word2[p2]);
            ++p2;
        }

        return res;
    }
};