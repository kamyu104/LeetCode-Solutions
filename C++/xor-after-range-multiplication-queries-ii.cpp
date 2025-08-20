// Time:  O(qlogm + (q + n) * sqrt(n))
// Space: O(n * sqrt(n))

// sqrt decomposition, difference array
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [](uint32_t a, uint32_t b, uint32_t mod) {
            a %= mod;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % mod;
                }
                a = uint64_t(a) * a % mod;
                b >>= 1;
            }
            return result;
        };

        const auto& inv = [&](int x, int p) {
            return powmod(x, p - 2, p);
        };

        const int block_size = sqrt(size(nums)) + 1;
        unordered_map<int, vector<int64_t>> diffs;
        for (const auto& q : queries) {
            int64_t l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= block_size) {
                if (!diffs.count(k)) {
                    diffs[k].assign(size(nums), 1);
                }
                diffs[k][l] = (diffs[k][l] * v) % MOD;
                r += k - (r - l) % k;
                if (r < size(nums)) {
                    diffs[k][r] = (diffs[k][r] * inv(v, MOD)) % MOD;
                }
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (nums[i] * v) % MOD;
                }
            }
        }
        for (auto& [k, diff] : diffs) {
            for (int i = 0; i < size(diff); ++i) {
                if (i - k >= 0) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (nums[i] * diff[i]) % MOD;
            }
        }
        return accumulate(cbegin(nums), cend(nums), 0, [](const auto& accu, const auto& x) {
            return accu ^ x;
        });
    }
};
