class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // Order by std::pair<double, std::size_t> 
        // Where double is the distance and std::size_t is the index

        std::priority_queue<
            std::pair<double, std::size_t>,
            std::vector<std::pair<double, std::size_t>>,
            std::less<std::pair<double, std::size_t>>
        > pq;

        for (std::size_t i{0uz}; i < points.size(); ++i) {

            int x = points[i][0];
            int y = points[i][1];
            double distance = std::sqrt(x * x + y * y);

            pq.push({distance, i});

            if (pq.size() > k) pq.pop();
        }

        std::vector<vector<int>> res;
        
        for (int i = 0; i < k; ++i) {
            res.emplace_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};
