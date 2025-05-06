#include<stdio.h>

public class Solution {
    public:
        const int MOD = 1e9 + 7;
        template <typename T>
        inline T mod_add(T a, T b, T m) { return (a % m + b % m) % m; }
        vector<int> dp;
        int rec(int idx) {
            if (idx == 0) return 1;
            if (idx == 1) return 1;
            if (idx == 2) return 2;
            if (dp[idx] != -1) return dp[idx];
            auto ans = (2LL * rec(idx - 1)) % MOD;
            ans = mod_add<long long>(ans, rec(idx - 3), MOD);
            
            return dp[idx] = ans;
        }
    
    
        int numTilings(int n) {
            dp.assign(n + 1, -1);
            return rec(n);
        }
    };

