// Time:  O(m + n)
// Space: O(1)

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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int left = max(A[i].start, B[j].start);
            int right = min(A[i].end, B[j].end);
            if (left <= right) {
                result.emplace_back(left, right);
            }
            if (A[i].end < B[j].end) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
