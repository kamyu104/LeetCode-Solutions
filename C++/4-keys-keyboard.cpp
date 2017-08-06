// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int maxA(int N) {
        if (N < 7) {
            return N;
        }
        if (N == 10) {
            return 20;
        }
        auto n = N / 5 + 1;  // n3 + n4 increases one every 5 keys
        // (1) n     =     n3 +     n4
        // (2) N + 1 = 4 * n3 + 5 * n4
        //     5 x (1) - (2) => 5*n - N - 1 = n3
        auto n3 = 5 * n - N - 1;
        auto n4 = n - n3;
        return pow(3, n3) * pow(4, n4);
    }
};


// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int maxA(int N) {
        if (N < 7) {
            return N;
        }
        vector<int> dp(6);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 7; i <= N; ++i) {
            dp[i % 6] = max(dp[(i - 4) % 6] * 3, dp[(i - 5) % 6] * 4);
        }
        return dp[N % 6];
    }
};
