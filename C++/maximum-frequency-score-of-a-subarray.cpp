// Time:  O(n)
// Space: O(n)

// two pointers, sliding window, freq table, hash table
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        unordered_map<int, unordered_map<int, int>> lookup;
        const auto& powmod = [&](int n, int p) {
            if (!lookup.count(n) || !lookup[n].count(p)) {
                lookup[n][p] = p >= 2 ? (static_cast<int64_t>(lookup[n][p - 1]) * n) % MOD : n % MOD;  // assumed powmod(n, p-1) was accessed before powmod(n, p)
            }
            return lookup[n][p];
        };

        int result = 0, curr = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            if (i >= k) {
                curr = ((curr - powmod(nums[i - k], cnt[nums[i - k]])) % MOD + MOD) % MOD;
                --cnt[nums[i - k]];
                if (cnt[nums[i - k]]) {
                    curr = (curr + powmod(nums[i - k], cnt[nums[i - k]])) % MOD;
                }
            }
            if (cnt[nums[i]]) {
                curr = ((curr - powmod(nums[i], cnt[nums[i]])) % MOD + MOD) % MOD;
            }
            ++cnt[nums[i]];
            curr = (curr + powmod(nums[i], cnt[nums[i]])) % MOD;
            if (i >= k - 1) {
                result = max(result, curr);
            }
        }
        return result;
    }
};


// Time:  O(n)
// Space: O(n)
// two pointers, sliding window, freq table
class Solution2 {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [&](int a, int b) {
            a %= MOD;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % MOD;
                }
                a = int64_t(a) * a % MOD;
                b >>= 1;
            }
            return result;
        };

        int result = 0, curr = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            if (i >= k) {
                curr = ((curr - powmod(nums[i - k], cnt[nums[i - k]])) % MOD + MOD) % MOD;
                --cnt[nums[i - k]];
                if (cnt[nums[i - k]]) {
                    curr = (curr + powmod(nums[i - k], cnt[nums[i - k]])) % MOD;
                }
            }
            if (cnt[nums[i]]) {
                curr = ((curr - powmod(nums[i], cnt[nums[i]])) % MOD + MOD) % MOD;
            }
            ++cnt[nums[i]];
            curr = (curr + powmod(nums[i], cnt[nums[i]])) % MOD;
            if (i >= k - 1) {
                result = max(result, curr);
            }
        }
        return result;
    }
};
