// Time:  O(n * l)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        const auto& lcp = [&](int i, int j) {
            if (i < 0 || j >= size(words)) {
                return 0;
            }
            const auto& s1 = words[i], &s2 = words[j];
            const int l = min(size(s1), size(s2));
            for (int k = 0; k < l; ++k) {
                if (s1[k] != s2[k]) {
                    return k;
                }
            }
            return l;
        };

        vector<int> lcps(size(words) - 1);
        for (int i = 0; i < size(lcps); ++i) {
            lcps[i] = lcp(i, i + 1);
        }
        vector<int> right(size(lcps) + 2);
        for (int i = size(lcps) - 1; i >= 0; --i) {
            right[i] = max(right[i + 1], lcps[i]);
        }
        vector<int> result(size(words));
        for (int i = 0, left = 0; i < size(words); ++i) {
            if (i - 2 >= 0) {
                left = max(left, lcps[i - 2]);
            }
            result[i] = max({left, right[i + 1], lcp(i - 1, i + 1)});
        }
        return result;
    }
};
