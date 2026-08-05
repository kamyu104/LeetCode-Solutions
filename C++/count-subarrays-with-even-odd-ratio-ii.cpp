// Time:  O(nlogn)
// Space: O(n)

// sort, coordinate compression, fenwick tree
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

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + (nums[i] % 2 == 0 ? b : -a);
        }
        vector<int64_t> sorted_nums(prefix);
        ranges::sort(sorted_nums);
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int64_t, int> val_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            val_to_idx[sorted_nums[i]] = i;
        }
        BIT bit(size(val_to_idx));
        int64_t result = 0;
        for (int i = 0; i < size(prefix); ++i) {
            const auto& idx = val_to_idx[prefix[i]];
            result += i - bit.query(idx - 1);
            bit.add(idx, 1);
        }
        return result;
    }
};
