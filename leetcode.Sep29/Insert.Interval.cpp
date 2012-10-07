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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans(0);
        int n = intervals.size();
        bool ins = false;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i].end < newInterval.start)
            {
                ans.push_back(intervals[i]);
                continue;
            } 
            if (intervals[i].start > newInterval.end)
            {
                if (!ins) 
                {
                    ans.push_back(newInterval);
                    ins = true;
                }
                ans.push_back(intervals[i]);
                continue;
            }
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        if (!ins)
        {
            ans.push_back(newInterval);
            ins = true;
        }
        return ans;
    }
};
