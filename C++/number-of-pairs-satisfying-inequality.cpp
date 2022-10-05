// Time:  O(nlogn)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered set, binary search
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        int64_t result = 0;
        for (int i = 0; i < size(nums1); ++i) {
            result += os.order_of_key({(nums1[i] - nums2[i]) + diff + 1, 0});
            os.insert({nums1[i] - nums2[i], i});
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bit, fenwick tree, coordinate compression
class Solution2 {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        unordered_set<int> nums_set;
        for (int i = 0; i < size(nums1); ++i) {
            nums_set.emplace(nums1[i] - nums2[i]);
        }
        vector<int> sorted_nums(cbegin(nums_set), cend(nums_set));
        sort(begin(sorted_nums), end(sorted_nums));
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            num_to_idx[sorted_nums[i]] = i;
        }
        int64_t result = 0;
        BIT bit(size(num_to_idx));
        for (int i = 0; i < size(nums1); ++i) {
            result += bit.query(distance(cbegin(sorted_nums), upper_bound(cbegin(sorted_nums), cend(sorted_nums), (nums1[i] - nums2[i]) + diff)) - 1);
            bit.add(num_to_idx[nums1[i] - nums2[i]], 1);
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

// Time:  O(nlogn)
// Space: O(n)
// merge sort, two pointers
class Solution3 {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums(size(nums1));
        for (int i = 0; i < size(nums); ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        int64_t result = 0;
        const function<void (int, int)> merge_sort = [&](int left, int right) {
            if (left == right) {
                return;
            }
            const int mid = left + (right - left) / 2;
            merge_sort(left, mid);
            merge_sort(mid + 1, right);
            for (int l = left, r = mid + 1; l < mid + 1; ++l) {
                for (; r < right + 1 && nums[l] - nums[r] > diff; ++r);
                result += right - r + 1;
            }
            vector<int> tmp;
            for (int l = left, r = mid + 1; l < mid + 1 || r < right + 1;) {
                if (r >= right + 1 || (l < mid + 1 && nums[l] <= nums[r])) {
                    tmp.emplace_back(nums[l++]);
                } else {
                    tmp.emplace_back(nums[r++]);
                }
            }
            for (int i = 0; i < size(tmp); ++i) {
                nums[left + i] = tmp[i];
            }
        };
        merge_sort(0, size(nums) - 1);
        return result;
    }
};
