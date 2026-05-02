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
    int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int> bit_;
};

class Solution {
public:
    vector<int> countSmallerOppositeParity(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        ranges::sort(sorted_nums);
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            val_to_idx[sorted_nums[i]] = i;
        }
        vector<BIT> bit(2, BIT(size(val_to_idx)));
        vector<int> result(size(nums));
        for (int i = size(nums) - 1; i >= 0; --i) {
            const auto& idx = val_to_idx[nums[i]];
            result[i] = bit[1 ^ (nums[i] % 2)].query(idx - 1);
            bit[nums[i] % 2].add(idx, 1);
        }
        return result;
    }
};
