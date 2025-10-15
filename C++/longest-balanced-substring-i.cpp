// Time:  O(26 * n^2)
// Space: O(26)

// freq table
class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            vector<int> cnt(26);
            int unique = 0;
            for (int j = i; j < size(s); ++j) {
                if (++cnt[s[j] - 'a'] == 1) {
                    ++unique;
                }
                if ((j - i + 1) % unique == 0 && (j - i + 1) / unique == ranges::max(cnt)) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

// Time:  O(a * n^2), a = len(set(s))
// Space: O(a)
// freq table
class Solution2 {
public:
    int longestBalanced(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            unordered_map<char, int> cnt;
            for (int j = i; j < size(s); ++j) {
                ++cnt[s[j]];
                if ((j - i + 1) % size(cnt) == 0 && (j - i + 1) / size(cnt) == max_element(cbegin(cnt), cend(cnt), [](const auto& a, const auto& b) {
                    return a.second < b.second;
                })->second) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};
