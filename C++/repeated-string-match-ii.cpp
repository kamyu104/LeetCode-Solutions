// Time:  O(n + m)
// Space: O(n + m)

// kmp, Fine and Wilf's Theorem
const auto& KMP = [](const auto& text, const auto& pattern) {
    const auto& getPrefix = [](const auto& pattern) {
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

    const vector<int> prefix = getPrefix(pattern);
    int j = -1;
    for (int i = 0; i < size(text); ++i) {
        while (j > -1 && pattern[j + 1] != text[i]) {
            j = prefix[j];
        }
        if (pattern[j + 1] == text[i]) {
            ++j;
        }
        if (j == size(pattern) - 1) {
            return i - j;
        }
    }
    return -1;
};

class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        const int64_t n = size(a), m = size(b);
        const auto& g = gcd(n, m);
        const auto& l = min(m * y, n + m - g);
        const auto& cnt = min(l == n + m - g ? g : n, n * x - m * y + 1);
        if (cnt - 1 < 0) {
            return false;
        }
        string text(l + (cnt - 1), 0);
        for (int64_t i = 0; i < size(text); ++i) {
            text[i] = a[i % n];
        }
        string pattern(l, 0);
        for (int64_t i = 0; i < size(pattern); ++i) {
            pattern[i] = b[i % m];
        }
        return KMP(text, pattern) != -1;
    }
};
