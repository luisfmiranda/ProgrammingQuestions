#include <iostream>
#include <vector>

using namespace std;

/*
 * - Problem:
 * Merge overlapping intervals
 *
 * - Problem description:
 * Given a collection of intervals, merge all overlapping intervals.
 */

// interval definition
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

vector<Interval> mergeOverlappingIntervals(vector<Interval>& intervals) {
    if (intervals.size() <= 1) return intervals;

    sort(intervals.begin(), intervals.end(), compareIntervals);

    // the variables first and second represent the indices of the two intervals compared at each generation
    int first = 0;

    for (int second = 1; second < intervals.size(); second++) {
        // intervals overlap
        if (intervals[first].end >= intervals[second].start) {
            // merge intervals
            intervals[first].end = max(intervals[first].end, intervals[second].end);
        // intervals do not overlap. Just move foward.
        } else {
            first++;
            intervals[first].start = intervals[second].start;
            intervals[first].end = intervals[second].end;
        }
    }

    intervals.erase(intervals.begin() + first + 1, intervals.end());
    return intervals;
}

void mergeOverlappingIntervalsTester() {
    Interval A = Interval(1, 3);
    Interval B = Interval(2, 6);
    Interval C = Interval(8, 10);
    Interval D = Interval(15, 18);

    vector<Interval> intervals = {A, B, C, D};

    mergeOverlappingIntervals(intervals);
}
