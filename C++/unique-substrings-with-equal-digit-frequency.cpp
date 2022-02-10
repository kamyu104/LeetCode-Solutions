// Time:  O(n^2)
// Space: O(n^2)

// rolling hash
class Solution {
public:
    int equalDigitFrequency(string s) {
        static const int MOD = 1e9 + 7;
        static const int D = 27;

        unordered_set<int> lookup;
        for (int i = 0; i < size(s); ++i) {
            unordered_map<int, int> cnt;
            int64_t h = 0;
            int max_cnt = 0;
            for (int j = i; j < size(s); ++j) {
                const int d = s[j] - '0' + 1;
                h = (h * D + d) % MOD;
                ++cnt[d];
                max_cnt = max(max_cnt, cnt[d]);
                if (size(cnt) * max_cnt == j - i + 1) {
                    lookup.emplace(h);
                }
            }
        }
        return size(lookup);
    }
};
