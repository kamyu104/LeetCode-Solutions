// Time:  O(nlogn)
// Space: O(n)

// fenwick tree
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int cnt = 0, inv = 0;
        int mn = size(nums) + 1;
        BIT bit(size(nums));
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (mn < i + 2 || min(mn, nums[i]) < i + 1) {
                cnt += locked[i];
            }
            mn = min(mn, nums[i]);
            inv += bit.query(nums[i] - 1);
            bit.add(nums[i], 1);
        }
        return cnt <= k ? cnt + inv : -1;
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

// ordered set
class Solution2 {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
        int cnt = 0, inv = 0;
        int mn = size(nums) + 1;
        ordered_set os;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (mn < i + 2 || min(mn, nums[i]) < i + 1) {
                cnt += locked[i];
            }
            mn = min(mn, nums[i]);
            inv += os.order_of_key(nums[i]);
            os.insert(nums[i]);
        }
        return cnt <= k ? cnt + inv : -1;
    }
};
