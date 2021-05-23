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

// Time:  O(n)
// Space: O(n)

// bfs solution
class Solution2 {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q({0});
        int reachable = 0, i = -1;
        while (!empty(q)) {
            i = q.front(); q.pop();
            for (int j = max(i + minJump, reachable + 1); j <= min(i + maxJump, int(size(s)) - 1); ++j) {
                if (s[j] != '0') {
                    continue;
                }
                q.emplace(j);
            }
            reachable = i + maxJump;
        }
        return i == size(s) - 1;
    }
};
