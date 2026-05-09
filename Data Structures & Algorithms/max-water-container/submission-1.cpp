class Solution {
public:

    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int bestArea = 0;

        while (l < r) {
            int l_h = heights[l];
            int r_h = heights[r];
            int area = std::min(l_h, r_h) * (r - l);
            bestArea = std::max(bestArea, area);

            if (l_h > r_h) {
                --r;
            } else {
                ++l;
            }

        }

        return bestArea;
    }
};
