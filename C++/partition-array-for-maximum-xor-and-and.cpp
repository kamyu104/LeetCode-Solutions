// Time:  O(nlogr * 2^n)
// Space: O(2^n)

// bitmasks, greedy
class Solution {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int l = bit_length(ranges::max(nums));
        const int n = size(nums);
        const int full_mask = (1 << n) - 1;
        vector<int> and_arr(1 << n);
        vector<int> xor_arr(1 << n);
        for (int mask = 1; mask < (1 << n); ++mask) {
            const auto& lb = mask & -mask;
            const auto& i = __builtin_ctz(lb);
            and_arr[mask] = (mask ^ lb) ? (and_arr[mask ^ lb] & nums[i]) : nums[i];
            xor_arr[mask] = xor_arr[mask ^ lb] ^ nums[i];
        }
        int64_t result = 0;
        vector<int> base(l);  // to improve performance
        for (int mask = 1; mask < (1 << n); ++mask) {
            const auto& total_and = and_arr[mask];
            const auto& total_xor = xor_arr[full_mask ^ mask];
            base.assign(l, 0);
            for (int remain = full_mask ^ mask; remain; remain &= remain - 1) {
                const int i = __builtin_ctz(remain);
                int x = nums[i] & ~total_xor;
                for (int i = l - 1; i >= 0; --i) {
                    if (!(x & (1 << i))) {
                        continue;
                    }
                    if (base[i] == 0) {
                        base[i] = x;
                        break;
                    }
                    x ^= base[i];
                }
            }
            int max_xor = 0;
            for (int i = l - 1; i >= 0; --i) {
                if ((max_xor ^ base[i]) > max_xor) {
                    max_xor ^= base[i];
                }
            }
            result = max(result, total_and + total_xor + static_cast<int64_t>(2) * max_xor);
        }
        return result;
    }
};

// Time:  O(nlogr * 2^n)
// Space: O(2^n)
// bitmasks, greedy
class Solution2 {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int l = bit_length(ranges::max(nums));
        const auto& max_xor_subset = [&](const vector<int>& nums) {  //# Time: O(nlogr)
            vector<int> base(l);
            for (auto x : nums) {  // gaussian elimination over GF(2)
                for (int i = l - 1; i >= 0; --i) {
                    if (!(x & (1 << i))) {
                        continue;
                    }
                    if (base[i] == 0) {
                        base[i] = x;
                        break;
                    }
                    x ^= base[i];
                }
            }
            int max_xor = 0;
            for (int i = l - 1; i >= 0; --i) {  // greedy
                if ((max_xor ^ base[i]) > max_xor) {
                    max_xor ^= base[i];
                }
            }
            return max_xor;
        };

        const int n = size(nums);
        const int full_mask = (1 << n) - 1;
        vector<int> and_arr(1 << n);
        vector<int> xor_arr(1 << n);
        for (int mask = 1; mask < (1 << n); ++mask) {
            const auto& lb = mask & -mask;
            const auto& i = __builtin_ctz(lb);
            and_arr[mask] = (mask ^ lb) ? (and_arr[mask ^ lb] & nums[i]) : nums[i];
            xor_arr[mask] = xor_arr[mask ^ lb] ^ nums[i];
        }
        int64_t result = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            const auto& total_and = and_arr[mask];
            const auto& total_xor = xor_arr[full_mask ^ mask];
            vector<int> needs;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    needs.emplace_back(nums[i] & ~total_xor);
                }
            }
            result = max(result, total_and + total_xor + static_cast<int64_t>(2) * max_xor_subset(needs));
        }
        return result;
    }
};

// Time:  O(nlogr * 2^n)
// Space: O(1)
// bitmasks, greedy
class Solution3 {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int l = bit_length(ranges::max(nums));
        const auto& max_xor_subset = [&](const vector<int>& nums) {  //# Time: O(nlogr)
            vector<int> base(l);
            for (auto x : nums) {  // gaussian elimination over GF(2)
                for (int i = l - 1; i >= 0; --i) {
                    if (!(x & (1 << i))) {
                        continue;
                    }
                    if (base[i] == 0) {
                        base[i] = x;
                        break;
                    }
                    x ^= base[i];
                }
            }
            int max_xor = 0;
            for (int i = l - 1; i >= 0; --i) {  // greedy
                if ((max_xor ^ base[i]) > max_xor) {
                    max_xor ^= base[i];
                }
            }
            return max_xor;
        };

        const int n = size(nums);
        int64_t result = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int and_val = -1;
            int xor_val = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    and_val = (and_val != -1) ? (and_val & nums[i]) : nums[i];
                } else {
                    xor_val ^= nums[i];
                }
            }
            vector<int> needs;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    needs.emplace_back(nums[i] & ~xor_val);
                }
            }
            result = max(result, and_val + xor_val + static_cast<int64_t>(2) * max_xor_subset(needs));
        }
        return result;
    }
};
