// Time:  O(n)
// Space: O(n)

// KMP solution.
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        vector<int> prefix = getPrefix(str);
        return prefix.back() != -1 &&
               (prefix.back() + 1) % (str.length() - prefix.back() - 1) == 0;
    }

private:
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
