// Time:  O(n)
// Space: O(n)

// KMP Algorithm
class Solution {
public:
    string shortestPalindrome(string s) {
            if (s.empty()) {
                return s;
            }
            string rev_s(s.crbegin(), s.crend());
            // Assume s is (Palindrome)abc,
            // A would be (Palindrome)abccba(Palindrome).
            string A = s + rev_s;
            auto prefix = getPrefix(A);
            // The index prefix.back() of A would be:
            // (Palindrome)abccba(Palindrome)
            //            ^
            // The index prefix.back() + 1 of s would be:
            // (Palindrome)abc
            //             ^
            // Get non palindrome part of s.
            string non_palindrome = s.substr(prefix.back() + 1);
            reverse(non_palindrome.begin(), non_palindrome.end());
            return non_palindrome + s;  // cba(Palindrome)abc.
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

// Time:  O(n)
// Space: O(n)
// Manacher's Algorithm
class Solution2 {
public:
    string shortestPalindrome(string s) {
            string T = preProcess(s);
            int n = T.length();
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; ++i) {
                int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

                P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

                // Attempt to expand palindrome centered at i
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                    ++P[i];
                }

                // If palindrome centered at i expand past R,
                // adjust center based on expanded palindrome.
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }

            // Find the max len of palindrome which starts with the first char of s.
            int max_len = 0;
            for (int i = 1; i < n - 1; ++i) {
                if (i - P[i] == 1) {
                    max_len = P[i];
                }
            }
            
            // Assume s is (Palindrome)abc.
            string ans = s.substr(max_len); // abc.
            reverse(ans.begin(), ans.end()); // cba.
            ans.append(s); // cba(Palindrome)abc.
            return ans;
        }
private:
    string preProcess(string s) {
        int n = s.length();
        if (n == 0) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < n; ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};
