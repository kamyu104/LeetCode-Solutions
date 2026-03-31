// Time:  precompute: O(rlogr)
//        runtime:    O(n * r)
// Space: O(r)

// dp, prefix sum
const int MOD = 1e9 + 7;
const int R = 5000;
const auto& total = [](int x) {
    int result = 0;
    for (; x; x /= 10) {
        result += x % 10;
    }
    return result;
};

const auto& precompute = [](int r) {
    vector<vector<int>> lookup(r + 1);
    for (int i = 0; i <= r; ++i) {
        lookup[total(i)].emplace_back(i);
    }
    return lookup;
};

const auto& LOOKUP = precompute(R);
class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        vector<pair<int, int>> dp = {{0, 1}};
        for (const auto& x : digitSum) {
            vector<pair<int, int>> new_dp;
            int prefix = 0, i = 0;
            for (const auto& v : LOOKUP[x]) {
                for (; i < size(dp); ++i) {
                    if (dp[i].first > v) {
                        break;
                    }
                    prefix = (prefix + dp[i].second) % MOD;
                }
                if (prefix) {
                    new_dp.emplace_back(v, prefix);
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (const auto& [_, c] : dp) {
            result = (result + c) % MOD;
        }
        return result;
    }
};
