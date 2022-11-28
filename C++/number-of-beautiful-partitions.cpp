// Time:  O(n * k)
// Space: O(n)

// dp
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        static const int MOD = 1e9 + 7;
        static const unordered_set<char> PRIMES = {'2', '3', '5', '7'};
        vector<int> dp(size(s));  // dp[i] at j : number of j beautiful partitions in s[:i+1] 
        for (int i = 0; i < size(s); ++i) {
            if (PRIMES.count(s[0]) && !PRIMES.count(s[i])) {
                dp[i] = 1;
            }
        }
        for (int j = 2; j <= k; ++j) {
            vector<int> new_dp(size(s));
            for (int i = j * minLength - 1, curr = 0; i < size(s); ++i) {
                if (PRIMES.count(s[i - minLength + 1])) {
                    curr = (curr + dp[i - minLength]) % MOD;
                }
                if (!PRIMES.count(s[i])) {
                    new_dp[i] = curr;
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
