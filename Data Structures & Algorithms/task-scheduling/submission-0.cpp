class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        std::vector<char> freq(26, 0);
        for (auto t : tasks) {
            ++freq[t - 'A'];
        }

        std::priority_queue<int> maxHeap;
        for (auto t : freq) {
            if (t > 0) {
                maxHeap.push(t);
            }
        }

        int time = 0;
        std::queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            ++time;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
