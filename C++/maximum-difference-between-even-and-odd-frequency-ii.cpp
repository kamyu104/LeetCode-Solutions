// Time:  O(d^2 * n)
// Space: O(n)

// prefix sum, two pointers, sliding window
class Solution {
public:
    int maxDifference(string s, int k) {
        static const auto POS_INF = numeric_limits<int>::max();
        static const auto NEG_INF = numeric_limits<int>::min();

        const auto& diff = [&](char x, char y) {
            vector<int> prefix1(size(s) + 1), prefix2(size(s) + 1), prefix(size(s) + 1);
            for (int i = 0; i < size(s); ++i) {
                prefix1[i + 1] = prefix1[i] + (s[i] == x ? 1 : 0);
                prefix2[i + 1] = prefix2[i] + (s[i] == y ? 1 : 0);
                prefix[i + 1] = prefix[i] + ((s[i] == x ? 1 : 0) - (s[i] == y ? 1 : 0));
            }
            int result = NEG_INF;
            vector<vector<int>> mn(2, vector<int>(2, POS_INF));
            for (int right = k - 1, left = 0; right < size(s); ++right) {
                for (; k <= right - left + 1 && prefix1[right + 1] - prefix1[left] && prefix2[right + 1] - prefix2[left]; ++left) {
                    const int i = prefix1[left] % 2;
                    const int j = prefix2[left] % 2;
                    mn[i][j] = min(mn[i][j], prefix[left]);
                }
                const int i = prefix1[right + 1] % 2;
                const int j = prefix2[right + 1] % 2;
                if (mn[i ^ 1][j] != POS_INF) {
                    result = max(result, prefix[right + 1] - mn[i ^ 1][j]);
                }
            }
            return result;
        };
        
        unordered_set<char> lookup(cbegin(s), cend(s));
        int result = NEG_INF;
        for (const auto& x : lookup) {
            for (const auto& y : lookup) {
                if (x != y) {
                    result = max(result, diff(x, y));
                }
            }
        }
        return result;
    }
};
