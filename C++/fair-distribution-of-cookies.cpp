// Time:  O(k * 3^n)
// Space: O(2^n)

// dp, submask enumeration
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> total(1 << size(cookies));
        for (int mask = 0; mask < (1 << size(cookies)); ++mask) {
            for (int i = 0; i < size(cookies); ++i) {
                if (mask & (1 << i)) {
                    total[mask] += cookies[i];
                }
            }
        }
        vector<vector<int>> dp(2, vector<int>(1 << size(cookies), numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int mask = 0; mask < (1 << size(cookies)); ++mask) {
                for (int submask = mask; submask; submask = (submask - 1) & mask) {
                    dp[(i + 1) % 2][mask] = min(dp[(i + 1) % 2][mask], max(total[submask], dp[i % 2][mask ^ submask]));
                }
            }
        }
        return dp[k % 2].back();
    }   
};
