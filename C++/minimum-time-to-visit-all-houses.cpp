// Time:  O(n + q)
// Space: O(n)

// prefix sum
class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        vector<int64_t> prefix1((2 * size(forward) - 1) + 1);
        for (int i = 0; i < 2 * size(forward) - 1; ++i) {
            prefix1[i + 1] = prefix1[i] + forward[i % size(forward)];
        }
        vector<int64_t> prefix2((2 * size(backward) - 1) + 1);
        for (int i = 0; i < 2 * size(backward) - 1; ++i) {
            prefix2[i + 1] = prefix2[i] + backward[i % size(backward)];
        }
        int64_t result = 0;
        int prev = 0;
        for (const auto& q : queries) {
            if (prev > q) {
                result += min(prefix1[q + size(forward)] - prefix1[prev], prefix2[prev + 1] - prefix2[q + 1]);
            } else {
                result += min(prefix1[q] - prefix1[prev], prefix2[prev + size(forward) + 1] - prefix2[q + 1]);
            }
            prev = q;
        }
        return result;
    }
};
