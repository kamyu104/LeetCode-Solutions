// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        // Manacher's Algorithm
        string longestPalindrome(string s) {
            string T = preProcess(s);
            int n = T.length();
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n-1; i++) {
                int i_mirror = 2*C-i; // equals to i' = C - (i-C)

                P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

                // Attempt to expand palindrome centered at i
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                    P[i]++;

                // If palindrome centered at i expand past R,
                // adjust center based on expanded palindrome.
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }

            // Find the maximum element in P.
            int maxLen = 0;
            int centerIndex = 0;
            for (int i = 1; i < n-1; i++) {
                if (P[i] > maxLen) {
                    maxLen = P[i];
                    centerIndex = i;
                }
            }

            return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
        }
    private:
        string preProcess(string s) {
            int n = s.length();
            if (n == 0) return "^$";
            string ret = "^";
            for (int i = 0; i < n; i++)
                ret += "#" + s.substr(i, 1);

            ret += "#$";
            return ret;
        }
};
