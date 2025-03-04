// Time:  O(n + m)
// Space: O(n + m)

// kmp, two pointers, sliding window, deque, greedy
class Solution {
public:
    string generateString(string str1, string str2) {
        const auto& getPrefix = [](const string& pattern) {
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
        };

        const int n = size(str1), m = size(str2);
        string candidate(n + m - 1, '*');
        auto prefix = getPrefix(str2);
        for (int i = 0, prev = -m; i < size(str1); ++i) {
            if (str1[i] != 'T') {
                continue;
            }
            const int diff = i - prev;
            if (diff < m) {
                if (prefix[m - 1] + 1 == m - diff) {
                    for (int j = 0; j < diff; ++j) {
                        candidate[(prev + m) + j] = str2[m - diff + j];
                    }
                } else {
                    return "";
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    candidate[i + j] = str2[j];
                }
            }
            prev = i;
        }
        string result = str2 + '#' + candidate;
        vector<int> idxs;
        for (int i = m + 1; i < size(result); ++i) {
            if (result[i] == '*') {
                result[i] = 'a';
                idxs.emplace_back(i);
            }
        }
        prefix = getPrefix(result);
        deque<int> dq;
        for (int i = m + 1, j = 0; i - (m + 1) < n;) {
            while (!empty(dq) && dq[0] < i) {
                dq.pop_front();
            }
            for (; j < size(idxs) && idxs[j] <= i + (m - 1); ++j) {
                dq.emplace_back(idxs[j]);
            }
            if (str1[i - (m + 1)] == 'F' && prefix[i + (m - 1)] + 1 == m) {
                if (empty(dq)) {
                    return "";
                }
                result[dq.back()] = 'b';
                i += m;
            } else {
                ++i;
            }
        }
        return result.substr(m + 1);
    }
};

// Time:  O(n + m)
// Space: O(n + m)
// z-function, two pointers, sliding window, deque, greedy
class Solution2 {
public:
    string generateString(string str1, string str2) {
        // Template: https://cp-algorithms.com/string/z-function.html
        const auto& z_function = [](const string& s) {  // Time: O(n), Space: O(n)
            vector<int> z(size(s));
            for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i, r = i + z[i] - 1;
                }
            }
            return z;
        };

        const int n = size(str1), m = size(str2);
        string candidate(n + m - 1, '*');
        auto z = z_function(str2);
        for (int i = 0, prev = -m; i < size(str1); ++i) {
            if (str1[i] != 'T') {
                continue;
            }
            const int diff = i - prev;
            if (diff < m) {
                if (z[diff] == m - diff) {
                    for (int j = 0; j < diff; ++j) {
                        candidate[(prev + m) + j] = str2[m - diff + j];
                    }
                } else {
                    return "";
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    candidate[i + j] = str2[j];
                }
            }
            prev = i;
        }
        string result = str2 + '#' + candidate;
        vector<int> idxs;
        for (int i = m + 1; i < size(result); ++i) {
            if (result[i] == '*') {
                result[i] = 'a';
                idxs.emplace_back(i);
            }
        }
        z = z_function(result);
        deque<int> dq;
        for (int i = m + 1, j = 0; i - (m + 1) < n;) {
            while (!empty(dq) && dq[0] < i) {
                dq.pop_front();
            }
            for (; j < size(idxs) && idxs[j] <= i + (m - 1); ++j) {
                dq.emplace_back(idxs[j]);
            }
            if (str1[i - (m + 1)] == 'F' && z[i]== m) {
                if (empty(dq)) {
                    return "";
                }
                result[dq.back()] = 'b';
                i += m;
            } else {
                ++i;
            }
        }
        return result.substr(m + 1);
    }
};
