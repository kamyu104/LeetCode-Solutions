// Time:  O(l)
// Space: O(l)

// brute force, longest prefix suffix, kmp algorithm
class Solution {
public:
    string minimumString(string a, string b, string c) {
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

        const auto& KMP = [&](const string& text, const string& pattern) {
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

        const auto& merge = [&](const auto& a, const auto& b) {
            if (KMP(b, a) != -1) {
                return b;
            }
            const auto& prefix = getPrefix(b + "#" + a);
            const auto& l = prefix.back() + 1;  // longest prefix suffix length
            return a + b.substr(l);
        };
    
        vector<string> result = {
            merge(a, merge(b, c)), merge(a, merge(c, b)),
            merge(b, merge(a, c)), merge(b, merge(c, a)),
            merge(c, merge(a, b)), merge(c, merge(b, a))
        };
        return *min_element(cbegin(result), cend(result), [](const auto& a, const auto& b) {
            return size(a) != size(b) ? size(a) < size(b) : a < b;
        });
    }
};

// Time:  O(l^2)
// Space: O(l)
// brute force
class Solution2 {
public:
    string minimumString(string a, string b, string c) {
        const auto& merge = [](const auto& a, const auto& b) {
            if (b.find(a) != string::npos) {
                return b;
            }
            int l = min(size(a), size(b));
            for (; l >= 0; --l) {
                int i = (size(a) - l), j = 0;
                for (; j < l; ++i, ++j) {
                    if (a[i] != b[j]) {
                        break;
                    }
                }
                if (j == l) {
                    break;
                }
            }
            return a + b.substr(l);
        };
    
        vector<string> result = {
            merge(a, merge(b, c)), merge(a, merge(c, b)),
            merge(b, merge(a, c)), merge(b, merge(c, a)),
            merge(c, merge(a, b)), merge(c, merge(b, a))
        };
        return *min_element(cbegin(result), cend(result), [](const auto& a, const auto& b) {
            return size(a) != size(b) ? size(a) < size(b) : a < b;
        });
    }
};
