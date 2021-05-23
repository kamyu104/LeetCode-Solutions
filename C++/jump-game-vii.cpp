// Time:  O(n)
// Space: O(n)

// dp with line sweep solution
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(size(s));
        dp[0] = true;
        for (int i = 1, cnt = 0; i < size(s); ++i) {
            if (i >= minJump) {
                cnt += dp[i - minJump];
            }
            if (i > maxJump) {
                cnt -= dp[i - maxJump - 1];
            }
            dp[i] = cnt > 0 && s[i] == '0';
        }
        return dp.back();
    }
};
