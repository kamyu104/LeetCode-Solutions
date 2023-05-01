// Time:  O(nlogn)
// Space: O(n)

// sort
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] < nums[b];
        });
        int64_t result = size(idxs);
        for (int i = 0; i + 1 < size(idxs); ++i) {
            if (idxs[i] > idxs[i + 1]) {
                result += size(idxs) - (i + 1);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, bit, fenwick tree
class Solution2 {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] < nums[b];
        });
        BIT bit(size(nums));
        int64_t result = size(nums);
        int prev = -1;
        for (const auto& i : idxs) {
            if (prev == -1) {
                result += i;
            } else if (prev < i) {
                result += (i - prev) - (bit.query(i) - bit.query(prev - 1));
            } else {
                result += ((size(nums) - 1) - bit.query(size(nums) - 1)) - ((prev - i) - (bit.query(prev) - bit.query(i - 1)));
            }
            bit.add(i, 1);
            prev = i;
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
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int> bit_;
    };
};
