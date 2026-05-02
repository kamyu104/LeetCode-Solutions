// Time:  O(nlogn)
// Space: O(n)

// sort, coordinate compression, fenwick tree, sliding window, dp
class BIT {
public:
    BIT(int n) : bit_(n + 1) {  // 0-indexed
    }
    
    void add(int i, int64_t val) {
        ++i;
        for (; i < size(bit_); i += lower_bit(i)) {
            bit_[i] = max(bit_[i], val);  // modified
        }
    }

    int64_t query(int i) const {
        ++i;
        int64_t total = 0;
        for (; i > 0; i -= lower_bit(i)) {
            total = max(total, bit_[i]);  // modified
        }
        return total;
    }

private:
    inline int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int64_t> bit_;
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        vector<int> sorted_nums(nums);
        ranges::sort(sorted_nums);
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            val_to_idx[sorted_nums[i]] = i;
        }
        vector<BIT> bit(2, BIT(size(val_to_idx)));
        vector<vector<int64_t>> dp(2, vector<int64_t>(size(nums)));
        for (int i = 0; i < size(nums); ++i) {
            if (i - k >= 0) {
                const auto& idx = val_to_idx[nums[i - k]];
                bit[0].add(idx, dp[0][i - k]);
                bit[1].add((size(val_to_idx) - 1) - idx, dp[1][i - k]);
            }
            const auto& idx = val_to_idx[nums[i]];
            dp[1][i] = bit[0].query(idx - 1) + nums[i];
            dp[0][i] = bit[1].query(((size(val_to_idx) - 1) - idx) - 1) + nums[i];
        }
        return max(ranges::max(dp[0]), ranges::max(dp[1]));
    }
};
