// Time:  O(nlogn)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + (b - 1)) / b;
        };
        sort(begin(jobs), end(jobs));
        sort(begin(workers), end(workers));
        int result = 0;
        for (int i = 0; i < size(jobs); ++i) {
            result = max(result, ceil_divide(jobs[i], workers[i]));
        }
        return result;
    }
};
