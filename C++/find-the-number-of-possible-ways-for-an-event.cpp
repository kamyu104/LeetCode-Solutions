// Time:  precompute: O(max_n^2 + max_y * min(max_n, max_x))
//        runtime:    O(min(n, x))
// Space: O(max_n^2 + max_y * min(max_n, max_x))

const int MOD = 1e9 + 7;
const int MAX_N = 1000, MAX_X = 1000, MAX_Y = 1000;
const int R = min(MAX_N, MAX_X);
vector<vector<int>> NCR(MAX_N + 1, vector<int>(MAX_N + 1));
vector<vector<int>> DP(MAX_N + 1, vector<int>(MAX_N + 1));
vector<vector<int>> POW(MAX_Y + 1, vector<int>(R + 1, 1));

void init() {
    if (NCR[0][0]) {
        return;
    }
    NCR[0][0] = DP[0][0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        NCR[i][0] = 1;
        for (int64_t j = 1; j <= i; ++j) {
            NCR[i][j] = (NCR[i - 1][j] + NCR[i - 1][j - 1]) % MOD;
            DP[i][j] = (DP[i - 1][j] * j + DP[i - 1][j - 1] * j) % MOD;
        }
    }
    for (int64_t i = 1; i <= MAX_Y; ++i) {
        for (int j = 1; j <= R; ++j) {
            POW[i][j] = (POW[i][j - 1] * i) % MOD;
        }
    }
}

// dp, combinatorics
class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        init();
        int result = 0;
        for (int i = 1; i <= min(n, x); ++i) {
            result = (result + (((static_cast<int64_t>(NCR[x][i]) * DP[n][i]) % MOD) * POW[y][i]) % MOD) % MOD;
        }
        return result;
    }
};
