// Time:  O(nlogn)
// Space: O(n)

// binary search, rolling hash
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        static const int64_t MOD = 1e9 + 7;
        static const int64_t B = 29;
        const int n = size(nums);
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<int64_t> prefix(n + 1);
        for (int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = (prefix[i] * B + nums[i]) % MOD;
        }
        vector<int64_t> base(n + 1, 1);
        for (int i = 0; i + 1 < size(base); ++i) {
            base[i + 1] = (base[i] * B) % MOD;
        }

        const auto& get_hash = [&](int l, int r) {
            if (l > r) {
                return static_cast<int64_t>(0);
            }
            return (prefix[r + 1] - prefix[l] * base[r - l + 1] % MOD + MOD) % MOD;
        };

        const auto& check = [&](int l) {
            unordered_map<int64_t, int> cnt;
            for (int i = 0; i + l - 1 < n; ++i) {
                ++cnt[get_hash(i, i + l - 1)];
            }
            for (const auto& [_, x] : cnt) {
                if (x == 1) {
                    return true;
                }
            }
            return false;
        };
        
        return binary_search(1, n - 1, check);
    }
};
