// Time:  O(n)
// Space: O(n)

// math, greedy, quick select
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        const int l = gcd(k, size(arr));
        int64_t result = 0;
        for (int i = 0; i < l; ++i) {
            vector<int> vals;
            for (int j = i; j < size(arr); j += l) {
                vals.emplace_back(arr[j]);
            }
            nth_element(begin(vals), begin(vals) + size(vals) / 2, end(vals));
            result += accumulate(cbegin(vals), cend(vals), 0LL,
                                 [&](const auto& total, const auto& x) {
                                     return total + abs(x - vals[size(vals) / 2]);
                                 });
        }
        return result;
    }
};
