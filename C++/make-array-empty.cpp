// Time:  O(nlogn)
// Space: O(n)

// sort
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            lookup[nums[i]] = i;
        }
        sort(begin(nums), end(nums));
        int64_t result = size(nums);
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (lookup[nums[i]] > lookup[nums[i + 1]]) {
                result += size(nums) - (i + 1);
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
        int64_t result = 0;
        int prev = -1;
        for (const auto& i : idxs) {
            if (prev < i) {
                result += prev != -1 ? 1 + ((i - prev) - (bit.query(i) - bit.query(prev - 1))) : i + 1;
            } else {
                result += (size(nums) - bit.query(size(nums) - 1)) - ((prev - i) - (bit.query(prev) - bit.query(i - 1)));
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
