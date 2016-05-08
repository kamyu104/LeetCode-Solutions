// Time:  O(n + k)
// Space: O(k)

// Wiki of KMP algorithm:
// http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        return KMP(haystack, needle);
    }

    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};


// Time:  O(n * k)
// Space: O(k)
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
