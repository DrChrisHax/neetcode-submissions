class Solution {
private:
    bool canFinish(int k, std::vector<int>& piles, int h) {
        long long t = 0;
        for (auto pile : piles) {
            t += std::ceil(static_cast<double>(pile) / k);
        }

        return h >= t;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int bestK = 0;
        for (auto p : piles) {
            bestK = std::max(p, bestK);
        }

        int l = 1, r = bestK;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;

            bool finished = canFinish(mid, piles, h);

            if (finished) {
                bestK = std::min(bestK, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return bestK;
    }
};
