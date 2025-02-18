// Time:  O(n + m)
// Space: O(n + m)

// kmp
class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
        static const int INF = numeric_limits<int>::max();

        const auto& getPrefix = [](const string& pattern) {
            vector<int> prefix(size(pattern), -1);
            int j = -1;
            for (int i = 1; i < size(pattern); ++i) {
                while (j != -1 && pattern[j + 1] != pattern[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == pattern[i]) {
                    ++j;
                }
                prefix[i] = j;
            }
            return prefix;
        };

        const int i = p.find('*');
        const auto& a = p.substr(0, i);
        const int j = p.find('*', i + 1);
        const auto& b = p.substr(i + 1, j - (i + 1));
        const auto& c = p.substr(j + 1);
        const int n = size(s), la = size(a), lb = size(b), lc = size(c);
        const auto& prefix1 = getPrefix(a + '#' + s);
        const auto& prefix2 = getPrefix(b + '#' + s);
        const auto& prefix3 = getPrefix(c + '#' + s);
        int result = INF;
        for (int i = 0, j = 0, k = 0; i + lb + lc < n; ++i) {
            for (; i < n && prefix1[la + 1 + i] + 1 != la; ++i);
            if (i >= n) {
                break;
            }
            for (; j < i + lb || (j < n && prefix2[lb + 1 + j] + 1 != lb); ++j);
            if (j >= n) {
                break;
            }
            for (; k < j + lc || (k < n && prefix3[lc + 1 + k] + 1 != lc); ++k);
            if (k >= n) {
                break;
            }
            result = min(result, k - (i - la));
        }
        return result != INF ? result : -1;
    }
};
