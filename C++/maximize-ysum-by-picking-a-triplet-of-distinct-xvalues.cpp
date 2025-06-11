// Time:  O(n)
// Space: O(n)

// hash table, quick select
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        static const int K = 3;
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(x); ++i) {
            lookup[x[i]] = max(lookup[x[i]], y[i]);
        }
        if (size(lookup) < K) {
            return -1;
        }
        vector<int> vals;
        vals.reserve(size(lookup));
        for (const auto& [_, v] : lookup) {
            vals.emplace_back(v);
        }
        nth_element(begin(vals), begin(vals) + (K - 1), end(vals), greater<int>());
        int result = 0;
        for (int i = 0; i < K; ++i) {
            result += vals[i];
        }
        return result;
    }
};
