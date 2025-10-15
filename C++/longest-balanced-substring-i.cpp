// Time:  O(n * (26 + n))
// Space: O(26)

// freq table
class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            vector<int> cnt(26);
            int mx = 0, unique = 0;
            for (int j = i; j < size(s); ++j) {
                if (++cnt[s[j] - 'a'] == 1) {
                    ++unique;
                }
                mx = max(mx, cnt[s[j] - 'a']);
                if ((j - i + 1) % unique == 0 && (j - i + 1) / unique == mx) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

// Time:  O(n * (a + n)), a = len(set(s))
// Space: O(a)
// freq table
class Solution2 {
public:
    int longestBalanced(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            unordered_map<char, int> cnt;
            int mx = 0;
            for (int j = i; j < size(s); ++j) {
                mx = max(mx, ++cnt[s[j]]);
                if ((j - i + 1) % size(cnt) == 0 && (j - i + 1) / size(cnt) == mx) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};
