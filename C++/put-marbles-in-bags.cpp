// Time:  O(n) on average
// Space: O(1)

// greedy, quick select
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        for (int i = 0; i + 1 < size(weights); ++i) {
            weights[i] += weights[i + 1];
        }
        weights.pop_back();
        int64_t result = 0;
        nth_element(begin(weights), begin(weights) + (k - 1), end(weights), greater<int>());
        for (int i = 0; i < k - 1; ++i) {
            result += weights[i];
        }
        nth_element(begin(weights), begin(weights) + (k - 1), end(weights));
        for (int i = 0; i < k - 1; ++i) {
            result -= weights[i];
        }
        return result;
    }
};
