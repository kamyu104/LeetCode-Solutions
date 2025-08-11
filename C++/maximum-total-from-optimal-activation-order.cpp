// Time:  O(nlogn)
// Space: O(n)

// sort, greedy
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<int> idxs(size(value));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return limit[a] != limit[b] ? limit[a] < limit[b] : value[a] > value[b];
        });
        int64_t result = 0;
        for (int i = 0, cnt = 0, prev = 0; i < size(idxs); ++i) {
            const auto& l = limit[idxs[i]];
            const auto& v = value[idxs[i]];
            if (l != prev) {
                cnt = 0;
                prev = l;
            }
            if (cnt < l) {
                result += v;
                ++cnt;
            }
        }
        return result;
    }
};
