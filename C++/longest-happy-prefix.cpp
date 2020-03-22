// Time:  O(n)
// Space: O(n)

// kmp solution
class Solution {
public:
    string longestPrefix(string s) {
        return s.substr(0, getPrefix(s).back() + 1);
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j != -1 && pattern[j + 1] != pattern[i]) {
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


// Time:  O(n) on average
// Space: O(1)
// rolling-hash solution
class Solution2 {
public:
    string longestPrefix(string s) {
        static const int M = 1e9 + 7;
        static const int D = 26;
        int result = 0;
        uint64_t prefix = 0, suffix = 0, power = 1;
        for (int i = 0; i + 1 < s.length(); ++i) {
            prefix = (prefix * D % M + (s[s.length() - (i + 1)] - 'a')) % M;
            suffix = (suffix + (s[i] - 'a') * power % M) % M;
            power = (power * D) % M;
            if (prefix == suffix) {
                // we assume M is a very large prime without hash collision
                // assert(check(i + 1, s));
                result = i + 1;
            }
        }
        return s.substr(0, result);
    }

private:
    bool check(int l, const string& s) {
        for (int i = 0; i < l; ++i) {
            if (s[i] != s[s.length() - l + i]) {
                return false;
            }
        }
        return true;
    }
};
