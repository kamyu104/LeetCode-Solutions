// Time:  O(n + m)
// Space: O(m)

// kmp
class Solution {
public:
    bool hasMatch(string s, string p) {
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

        const auto& KMP = [&](const string& text, const string& pattern, int i) {
            const vector<int> prefix = getPrefix(pattern);
            int j = -1;
            for (; i < size(text); ++i) {
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

        p.push_back('*');
        for (int i = 0, j = 0, k = 0; i < size(p); ++i) {
            if (p[i] != '*') {
                continue;
            }
            const auto& pattern = p.substr(j, i - j);
            j = i + 1;
            if (empty(pattern)) {
                continue;
            }
            k = KMP(s, pattern, k);
            if (k == -1) {
                return false;
            }
            k += size(pattern);
        }
        return true;
    }
};
