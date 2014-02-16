// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int longestValidParentheses(string s) {
            int ans = 0;

            int depth = 0;
            int last = -1;
            for(int i = 0; i < s.length(); ++i) {
                if(s[i] == '(') {
                    ++depth;
                }
                else {
                    --depth;
                    if(depth < 0) {
                        last = i;
                        depth = 0;
                    }
                    else {
                        if(depth == 0)
                            ans = max(ans, i - last);
                    }
                }
            }

            depth = 0;
            last = s.size();
            for(int i = s.length() - 1; i >= 0; --i) {
                if(s[i] == ')') {
                    ++depth;
                }
                else {
                    --depth;
                    if(depth < 0) {
                        last = i;
                        depth = 0;
                    }
                    else {
                        if(depth == 0)
                            ans = max(ans, last - i);
                    }
                }
            }

            return ans;
        }
};
