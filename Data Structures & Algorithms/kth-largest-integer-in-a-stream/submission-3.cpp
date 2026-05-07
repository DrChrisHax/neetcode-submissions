class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
        : pq_{nums.begin(), nums.end()}
        , k_{k}
    {
        while (pq_.size() > k_) {
            pq_.pop();
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if (pq_.size() > k_) pq_.pop();
        return pq_.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_;
    int k_;
};
