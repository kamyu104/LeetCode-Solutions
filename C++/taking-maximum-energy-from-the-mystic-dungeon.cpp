// Time:  O(n)
// Space: O(k)

// greedy, kadane's algorithm
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        static const int NEG_INF = numeric_limits<int>::min();

        vector<int> result(k, NEG_INF);
        for (int i = 0; i < size(energy); ++i) {
            result[i % k] = max(result[i % k], 0) + energy[i];
        }
        return ranges::max(result);
    }
};
