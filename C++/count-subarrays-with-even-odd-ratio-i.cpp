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
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + (nums[i] % 2 == 0 ? b : -a);
        }
        vector<int> sorted_nums(prefix);
        ranges::sort(sorted_nums);
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            val_to_idx[sorted_nums[i]] = i;
        }
        BIT bit(size(val_to_idx));
        int result = 0;
        for (int i = 0; i < size(prefix); ++i) {
            const auto& idx = val_to_idx[prefix[i]];
            result += i - bit.query(idx - 1);
            bit.add(idx, 1);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            vector<int> cnt(2);
            for (int j = i; j < size(nums); ++j) {
                ++cnt[nums[j] % 2];
                if (b * cnt[0] <= a * cnt[1]) {
                    ++result;
                }
            }
        }
        return result;
    }
};
