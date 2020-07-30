// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        static const int MOD = 1e9 + 7;
        int result = 0, accu = 0;
        vector<int> dp(2);
        ++dp[0];
        for (const auto& x : arr) {
            accu ^= x & 1;
             ++dp[accu];
            result = (result + dp[accu ^ 1]) % MOD;
        }
        return result;
    }
};
