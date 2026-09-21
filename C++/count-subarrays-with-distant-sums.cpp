// Time:  O(nlogn)
// Space: O(n)

// prefix sum, bit
class Solution {
public:
    long long distantSubarrays(const vector<int>& nums, int goal, int k) {
        if (k == 0) {
            return (size(nums) + 1) * size(nums) / 2;
        }
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int64_t> vals(prefix);
        ranges::sort(vals);
        vals.erase(begin(ranges::unique(vals)), end(vals));
        unordered_map<int, int> val_to_idx;
        for (const auto& [i, x] : views::enumerate(vals)) {
            val_to_idx[x] = i;
        }
        BIT bit(size(vals));
        bit.add(val_to_idx[0], 1);
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += bit.query(distance(begin(vals), ranges::upper_bound(vals, prefix[i + 1] - (goal + k))) - 1);
            result += (i + 1) - bit.query(distance(begin(vals), ranges::lower_bound(vals, prefix[i + 1] - (goal - k))) - 1);
            bit.add(val_to_idx[prefix[i + 1]], 1);
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
    
    private:
        inline int lower_bit(int i) const {
            return i & -i;
        }

        vector<int> bit_;
    };
};

// Time:  O(nlogn)
// Space: O(n)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// prefix sum, ordered set
class Solution2 {
public:
    long long distantSubarrays(const vector<int>& nums, int goal, int k) {
        static const auto& POS_INF = numeric_limits<int>::max();
        static const auto& NEG_INF = numeric_limits<int>::min();
        using ordered_set = tree<pair<int64_t, int>, null_type, less<pair<int64_t, int>>, rb_tree_tag, tree_order_statistics_node_update>;

        if (k == 0) {
            return (size(nums) + 1) * size(nums) / 2;
        }
        int64_t result = 0, prefix = 0;
        ordered_set os;
        os.insert({0, 0});
        for (int i = 0; i < size(nums); ++i) {
            prefix += nums[i];
            result += os.order_of_key({prefix - (goal + k), POS_INF}) + (size(os) - os.order_of_key({prefix - (goal - k), NEG_INF}));
            os.insert({prefix, i + 1});
        }
        return result;
    }
};
