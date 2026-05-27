/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    int minMeetingRooms(vector<Interval>& intervals) {

        auto cmp = [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        };

        std::sort(intervals.begin(), intervals.end(), cmp);

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const Interval& interval : intervals) {
            if (!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};
