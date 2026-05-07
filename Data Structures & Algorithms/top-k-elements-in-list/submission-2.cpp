class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::unordered_map<int, int> freq;

        for (const auto n : nums) {
            ++freq[n];
        }

        std::priority_queue<
            std::pair<int, int>, // freq, number
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>
        > pq;

        auto it = freq.begin();
        while (it != freq.end()) {
            pq.push({it->second, it->first});
            if (pq.size() > k) pq.pop();

            ++it;
        }

        std::vector<int> res;
        res.reserve(k);

        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
