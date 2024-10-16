// Time:  O(nlogn)
// Space: O(n)

// sort, prefix sum, two pointers, sliding window
class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        sort(begin(intervals), end(intervals));
        int result = 0;
        vector<int> prefix(size(intervals) + 1);
        for (int right = 0, left = 0, mx = numeric_limits<int>::min(); right < size(intervals); ++right) {
            prefix[right + 1] = prefix[right] + (mx < intervals[right][0] ? 1 : 0);
            mx = max(mx, intervals[right][1]);
            for (; intervals[right][0] - intervals[left][1] > k; ++left);
            result = max(result, prefix[right + 1] - prefix[left + 1]);
        }
        return prefix.back() - result;
    }
};
