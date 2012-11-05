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
public:
    static bool cmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start >= intervals[i - 1].start && intervals[i].start <= intervals[i - 1].end)
            {
                intervals[i - 1].end = max(intervals[i - 1].end, intervals[i].end);
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }
        return intervals;
    }
};
