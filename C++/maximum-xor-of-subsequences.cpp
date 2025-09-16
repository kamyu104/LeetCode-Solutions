// Time:  O(nlogr), r = max(nums)
// Space: O(r)

// bitmasks, greedy
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int l = bit_length(ranges::max(nums));
        const auto& max_xor_subset = [&](const vector<int>& nums) {  // Time: O(nlogr)
            vector<int> base;
            for (auto x : nums) {
                for (const auto& b : base) {  // gaussian elimination over GF(2)
                    if ((x ^ b) < x) {
                        x ^= b;
                    }
                }
                if (x) {
                    base.emplace_back(x);
                }
            }
            int max_xor = 0;
            for (const auto& b : base) {  // greedy
                if ((max_xor ^ b) > max_xor) {
                    max_xor ^= b;
                }
            }
            return max_xor;
        };

        return max_xor_subset(nums);
    }
};

// Time:  O(nlogr), r = max(nums)
// Space: O(r)
// bitmasks, greedy
class Solution2 {
public:
    int maxXorSubsequences(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int l = bit_length(ranges::max(nums));
        const auto& max_xor_subset = [&](const vector<int>& nums) {  // Time: O(nlogr)
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

        return max_xor_subset(nums);
    }
};
