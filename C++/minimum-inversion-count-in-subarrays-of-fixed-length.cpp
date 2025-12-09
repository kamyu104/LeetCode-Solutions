// Time:  O(nlogn)
// Space: O(n)

// sort, coordinate compression, fenwick tree, sliding window
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
    long long minInversionCount(vector<int>& nums, int k) {
        vector<int> vals(nums);
        ranges::sort(vals);
        vals.erase(unique(begin(vals), end(vals)), end(vals));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(vals); ++i) {
            val_to_idx[vals[i]] = i;
        }
        int64_t result = numeric_limits<int64_t>::max(), cnt = 0;
        BIT bit(size(val_to_idx));
        for (int i = 0; i < size(nums); ++i) {
            bit.add(val_to_idx[nums[i]], +1);
            cnt += bit.query(size(val_to_idx) - 1) - bit.query(val_to_idx[nums[i]]);
            if (i < k - 1) {
                continue;
            }
            result = min(result, cnt);
            cnt -= bit.query(val_to_idx[nums[i - (k - 1)]] - 1);
            bit.add(val_to_idx[nums[i - (k - 1)]], -1);
        }
        return result;
    }
};
