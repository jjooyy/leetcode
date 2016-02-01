/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool comp(Interval a, Interval b) {
        return a.start <= b.start;
    }
public:

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for (auto it = intervals.begin() + 1; it < intervals.end(); it++) {
            if((it-1)->end > it->start ) {
                return false;
            }
        }
        return true;
    }
};
