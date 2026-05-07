class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<
            int, 
            std::vector<int>, 
            std::less<int>> 
        pq{stones.begin(), stones.end()};

        while (pq.size() > 1) {
            int stone_1 = pq.top();
            pq.pop();
            int stone_2 = pq.top();
            pq.pop();
            int weight = stone_1 - stone_2;
            if (weight) pq.push(weight);
        }
        
        if (pq.empty()) {
            return 0;
        } else {
            return pq.top();
        }
    }
};
