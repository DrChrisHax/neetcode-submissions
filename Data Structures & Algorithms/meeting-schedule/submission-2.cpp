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

    static constexpr bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);

        std::size_t n = intervals.size();
        for (std::size_t i = 1; i < n; ++i) {
            if (intervals[i-1].end > intervals[i].start) return false;
        }

        return true;
    }
};
