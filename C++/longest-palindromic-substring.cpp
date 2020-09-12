// Time:  O(n)
// Space: O(n)

// Manacher's Algorithm.
class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        const int n = T.length();
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                ++P[i];
            }

            // If palindrome centered at i expands the past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P.
        int max_i = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > P[max_i]) {
                max_i = i;
            }
        }

        return s.substr((max_i - P[max_i]) / 2, P[max_i]);
    }

private:
    string preProcess(const string& s) {
        if (s.empty()) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution2 {
public:
    string longestPalindrome(string s) {
        int left = -1, right = -2;
        for (int i = 0; i < size(s); ++i) {
            int len = max(expand(s, i, i), expand(s, i, i + 1));
            if (len > right - left - 1) {
                right = i + len / 2;
                left = right - len + 1;
            }
        }
        return left >= 0 ? s.substr(left, right - left + 1) : "";
    }

private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < size(s) && s[left] == s[right]) {
            --left, ++right;
        }
        return (right - left + 1) - 2;
    }
};
