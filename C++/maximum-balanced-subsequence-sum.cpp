// Time:  O(nlogn)
// Space: O(n)

// bst, binary search, mono stack
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        const auto& query = [](const auto& bst, const auto& k) {
            const auto it = bst.lower_bound(pair(k, 0));
            return it != begin(bst) ? prev(it)->second : NEG_INF;
        };

        const auto& update = [](auto& bst, const auto& k, const auto& v) {
            const auto it = bst.lower_bound(pair(k, 0));
            if (it != end(bst) && it->first == k) {
                if (!(it->second < v)) {
                    return;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < v)) {
                return;
            }
            const auto [jt, _] = bst.emplace(k, v);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        };

        int64_t result = NEG_INF;
        set<pair<int, int64_t>> bst;
        for (int i = 0; i < size(nums); ++i) {
            const int64_t val = max(query(bst, (nums[i] - i) + 1), static_cast<int64_t>(0)) + nums[i];
            result = max(result, val);
            update(bst, nums[i] - i, val);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bit, fenwick tree
class Solution2 {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        unordered_set<int> vals_set;
        for (int i = 0; i < size(nums); ++i) {
            vals_set.emplace(nums[i] - i);
        }
        vector<int> sorted_vals(cbegin(vals_set), cend(vals_set));
        sort(begin(sorted_vals), end(sorted_vals));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_vals); ++i) {
            val_to_idx[sorted_vals[i]] = i;
        }
        int64_t result = NEG_INF;
        const auto& fn = [](int64_t a, int64_t b) {
            return max(a, b);
        };
        BIT bit(size(val_to_idx), NEG_INF, fn);
        for (int i = 0; i < size(nums); ++i) {
            const auto x = bit.query(val_to_idx[nums[i] - i]);
            const int64_t val = max(bit.query(val_to_idx[nums[i] - i]), static_cast<int64_t>(0)) + nums[i];
            result = max(result, val);
            bit.update(val_to_idx[nums[i] - i], val);
        }
        return result;
    }

private:
    class BIT {
    public:
        BIT(int n, int64_t val, const function<int64_t (int64_t, int64_t)> fn)
          : bit_(n + 1, val),
            fn_(fn) {  // 0-indexed
        }
        
        void update(int i, int64_t val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] = fn_(bit_[i], val);
            }
        }

        int64_t query(int i) const {
            ++i;
            int64_t total = bit_[0];
            for (; i > 0; i -= lower_bit(i)) {
                total = fn_(total, bit_[i]);
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int64_t> bit_;
        const function<int64_t (int64_t, int64_t)> fn_;
    };
};
