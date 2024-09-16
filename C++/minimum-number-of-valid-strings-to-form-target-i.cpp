// Time:  O(n + w * l)
// Space: O(w * l)

// rolling hash, prefix sum, hash table, greedy
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        static const int MOD = 1e9 + 7, P = 131;
        vector<int64_t> power = {1};
        vector<int64_t> prefix = {0};
        const auto& hash = [&](int l, int r) {
            return ((prefix[r+1] - prefix[l] * power[r - l + 1]) % MOD + MOD) % MOD;
        };

        for (const auto& x : target) {
            power.emplace_back(power.back() * P % MOD);
            prefix.emplace_back((prefix.back() * P + (x - 'a' + 1)) % MOD);
        }
        unordered_set<int> lookup;
        for (const auto& w : words) {
            int64_t h = 0;
            for (const auto& x : w) {
                h = (h * P + (x - 'a' + 1)) % MOD;
                lookup.emplace(h);
            }
        }
        int result = 0;
        int left = -1, right = -1, r = 0;
        while (r != right) {
            left = right + 1;
            right = r;
            ++result;
            for (int l = left; l <= right; ++l) {
                while (lookup.count(hash(l, r))) {
                    if (++r == size(target)) {
                        return result;
                    }
                }
            }
        }
        return -1;
    }
};
