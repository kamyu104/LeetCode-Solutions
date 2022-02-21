// Time:  O(nlogn)
// Space: O(n)

// bit, fenwick tree, combinatorics
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums1); ++i) {
            lookup[nums1[i]] = i;
        }
        int64_t result = 0;
        BIT bit(size(nums1));
        for (int i = 0; i < size(nums2); ++i) {
            const int64_t smaller = bit.query(lookup[nums2[i]] - 1);
            const int64_t larger = (size(nums1) - (lookup[nums2[i]] + 1)) - (i - smaller);
            result += smaller * larger;
            bit.add(lookup[nums2[i]], 1);
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
