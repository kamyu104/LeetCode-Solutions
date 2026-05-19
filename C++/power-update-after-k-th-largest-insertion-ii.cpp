// Time:  O((n + q) * log(n * q) + q * logr)
// Space: O(n + q)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered set, fast exponentiation
class Solution {
public:
    vector<int> powerUpdate(vector<int>& nums, int p, vector<vector<int>>& queries) {
        static const uint32_t MOD = 1e9 + 7;

        const auto& powmod = [&](uint32_t a, uint32_t b, uint32_t mod) {
            a %= mod;
            uint32_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (static_cast<uint64_t>(result) * a) % mod;
                }
                a = (static_cast<uint64_t>(a) * a) % mod;
                b >>= 1;
            }
            return result;
        };

        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        int i = 0;
        for (; i < size(nums); ++i) {
            os.insert({nums[i], i});
        }
        vector<int> result;
        result.reserve(size(queries));
        for (const auto& q : queries) {
            os.insert({q[0], i++});
            p = powmod(p, os.find_by_order(size(os) - q[1])->first, MOD);
            result.emplace_back(p);
        }
        return result;
    }
};

// Time:  O((n + q) * log(n * q) + q * logr)
// Space: O(n + q)
// sort, coordinate compression, fenwick tree, fast exponentiation
class Solution2 {
public:
    vector<int> powerUpdate(vector<int>& nums, int p, vector<vector<int>>& queries) {
        static const uint32_t MOD = 1e9 + 7;

        const auto& powmod = [&](uint32_t a, uint32_t b, uint32_t mod) {
            a %= mod;
            uint32_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (static_cast<uint64_t>(result) * a) % mod;
                }
                a = (static_cast<uint64_t>(a) * a) % mod;
                b >>= 1;
            }
            return result;
        };

        vector<int> sorted_vals(nums);
        for (const auto& q : queries) {
            sorted_vals.emplace_back(q[0]);
        }
        ranges::sort(sorted_vals);
        sorted_vals.erase(unique(begin(sorted_vals), end(sorted_vals)), end(sorted_vals));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_vals); ++i) {
            val_to_idx[sorted_vals[i]] = i;
        }
        BIT bit(size(val_to_idx));
        for (const auto& x : nums) {
            bit.add(val_to_idx[x], +1);
        }
        vector<int> result;
        result.reserve(size(queries));
        int total = size(nums);
        for (const auto& q : queries) {
            bit.add(val_to_idx[q[0]], +1);
            const auto& i = bit.kth_element(++total - q[1] + 1);
            p = powmod(p, sorted_vals[i], MOD);
            result.emplace_back(p);
        }
        return result;
    }

private:
    class BIT {
    public:
        BIT(int n) : bit_(n + 1) {  // 0-indexed
        }
        
        void add(int i, int val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] += val;
            }
        }

        int query(int i) const {
            ++i;
            int total = 0;
            for (; i > 0; i -= lower_bit(i)) {
                total += bit_[i];
            }
            return total;
        }
        
        int kth_element(int k) const {
            int total = 0;
            int pos = 0;
            for (int i = floor_log2_x(size(bit_) - 1); i >= 0; --i) {
                if (pos + (1 << i) < size(bit_) && !(total + bit_[pos + (1 << i)] >= k)) {
                    total += bit_[pos + (1 << i)];
                    pos += (1 << i);
                }
            }
            return (pos + 1) - 1;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        int floor_log2_x(int x) const {
            return bit_width(static_cast<uint32_t>(x)) - 1;
        };
        
        vector<int> bit_;
    };
};
