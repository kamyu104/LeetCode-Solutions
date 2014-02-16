// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int numDecodings(string s) {
            if(s.empty()) return 0;

            int prev = 0; // f[n - 2]
            int cur = 1;  // f[n - 1]

            for(int i = 1; i <= s.length(); ++i) {
                if(s[i - 1] == '0')
                    cur = 0; // f[n - 1] = 0
                if(i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                    prev = 0; // f[n - 2] = 0;

                int tmp = cur;
                cur += prev; // f[n] = f[n - 1] + f[n - 2]
                prev = tmp;
            }

            return cur;
        }
};
