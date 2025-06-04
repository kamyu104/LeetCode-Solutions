// Time:  O(n + m)
// Space: O(n + m)

// kmp algorithm
class Solution {
public:
    string shortestSuperstring(string s1, string s2) {
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
                    break;
                }
            }
            return text + pattern.substr(j + 1);  // modified
        };

        const auto& result1 = KMP(s1, s2);
        const auto& result2 = KMP(s2, s1);
        return size(result1) < size(result2) ? result1 : result2;
    }
};
