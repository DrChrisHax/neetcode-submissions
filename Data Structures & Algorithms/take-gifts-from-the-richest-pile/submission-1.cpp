class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        std::priority_queue<int> pq{gifts.begin(), gifts.end()};

        for (int i = 0; i < k; ++i) {
            int largest = pq.top();
            pq.pop();
            pq.push(std::sqrt(largest));
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();   
        }

        return sum;

    }
};