// Time:  precompute: O(max_r^2 * log(max_r))
//        runtime:    O(n + r^2)
// Space: O(max_r^2)

// number theory, mobius function, principle of inclusion-exclusion
const int MOD = 1e9 + 7;
const int MAX_NUM = 200;
const auto& init = []() {
    vector<int> POW2(MAX_NUM + 1, 1);
    for (int i = 0; i + 1 < size(POW2); ++i) {  // Time: O(max_r)
        POW2[i + 1] = (POW2[i] * 2ll) % MOD;
    }
    vector<int> POW3(MAX_NUM + 1, 1);
    for (int i = 0; i + 1 < size(POW3); ++i) {  // Time: O(max_r)
        POW3[i + 1] = (POW3[i] * 3ll) % MOD;
    }
    vector<vector<int>> LCM(MAX_NUM + 1, vector<int>(MAX_NUM + 1));
    for (int i = 1; i <= MAX_NUM; ++i) {  // Time: O(max_r^2 * log(max_r))
        for (int j = i; j <= MAX_NUM; ++j) {
            LCM[i][j] = LCM[j][i] = lcm(i, j);
        }
    }
    vector<int> MU(MAX_NUM + 1);
    MU[1] = 1;
    for (int i = 1; i <= MAX_NUM; ++i) {  // Time: O(max_r * log(max_r))
        for (int j = i + i; j <= MAX_NUM; j += i) {
            MU[j] -= MU[i];
        }
    }
    return tuple(POW2, POW3, LCM, MU);
};

const auto& [POW2, POW3, LCM, MU] = init();
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int mx = ranges::max(nums);
        vector<int> cnt(mx + 1);
        for (const auto& x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            for (int j = i + i; j <= mx; j += i) {
                cnt[i] = (cnt[i] + cnt[j]) % MOD;
            }
        }
        vector<vector<int>> f(mx + 1, vector<int>(mx + 1));
        for (int g1 = 1; g1 <= mx; ++g1) {
            for (int g2 = g1; g2 <= mx; ++g2) {
                const int l = LCM[g1][g2];
                const int c = l < size(cnt) ? cnt[l] : 0;
                const int c1 = cnt[g1], c2 = cnt[g2];
                f[g1][g2] = f[g2][g1] = ((static_cast<int64_t>(POW3[c]) * POW2[(c1 - c) + (c2 - c)] - POW2[c1] - POW2[c2] + 1) % MOD + MOD) % MOD;
            }
        }
        const auto& count = [&](int g) {
            int result = 0;
            for (int i = 1; i <= mx / g; ++i) {
                for (int j = 1; j <= mx / g; ++j) {
                    result = ((result + MU[i] * MU[j] * f[i * g][j * g]) % MOD + MOD) % MOD;
                }
            }
            return result;
        };
    
        int result = 0;
        for (int g = 1; g <= mx; ++g) {  // Time: O(mx^2 * (1 + 1/4 + 1/9 + ... + (1/mx)^2))) = O(mx^2 * pi^2/6), see https://en.wikipedia.org/wiki/Basel_problem
            result = (result + count(g)) % MOD;
        }
        return result;
    }
};

// Time:  O(n * r^2 * logr)
// Space: O(r^2)
// dp, number theory
class Solution2 {
public:
    int subsequencePairCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        const int mx = ranges::max(nums);
        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));
        dp[0][0] = 1;
        for (const auto& x : nums) {
            vector<vector<int>> new_dp(dp);
            for (int g1 = mx; g1 >= 0; --g1) {
                for (int g2 = mx; g2 >= 0; --g2) {
                    const auto& ng1 = gcd(g1, x);
                    const auto& ng2 = gcd(g2, x);
                    new_dp[ng1][g2] = (new_dp[ng1][g2] + dp[g1][g2]) % MOD;
                    new_dp[g1][ng2] = (new_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (int g = 1; g <= mx; ++g) {
            result = (result + dp[g][g]) % MOD;
        }
        return result;
    }
};

// Time:  O(n * r^2 * logr)
// Space: O(r^2)
// dp, number theory
class Solution3 {
public:
    int subsequencePairCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, unordered_map<int, int>> dp;
        dp[0][0] = 1;
        for (const auto& x : nums) {
            unordered_map<int, unordered_map<int, int>> new_dp;
            for (const auto& [g1, dp_g1] : dp) {
                for (const auto& [g2, cnt] : dp_g1) {
                    const auto& ng1 = gcd(g1, x);
                    const auto& ng2 = gcd(g2, x);
                    new_dp[g1][g2] = (new_dp[g1][g2] + cnt) % MOD;
                    new_dp[ng1][g2] = (new_dp[ng1][g2] + cnt) % MOD;
                    new_dp[g1][ng2] = (new_dp[g1][ng2] + cnt) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (const auto& [g1, dp_g1] : dp) {
            if (g1 == 0) {
                continue;
            }
            for (const auto& [g2, cnt] : dp_g1) {
                if (g2 != g1) {
                    continue;
                }
                result = (result + cnt) % MOD;
            }
        }
        return result;
    }
};
