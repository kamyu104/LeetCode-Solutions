// Time:  O(n)
// Space: O(1)

// sort
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int right = 0, left = 0, mx = 0; right < size(nums); ++right) {
            if (right + 1 != size(nums) && __builtin_popcount(nums[right + 1]) == __builtin_popcount(nums[right])) {
                continue;
            }
            if (mx > *min_element(cbegin(nums) + left, cbegin(nums) + right + 1)) {
                return false;
            }
            mx = *max_element(cbegin(nums) + left, cbegin(nums) + right + 1);
            left = right + 1;
        }
        return true;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    bool canSortArray(vector<int>& nums) {
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (right + 1 != size(nums) && __builtin_popcount(nums[right + 1]) == __builtin_popcount(nums[right])) {
                continue;
            }
            sort(begin(nums) + left, begin(nums) + right + 1);
            left = right + 1;
        }
        return is_sorted(cbegin(nums), cend(nums));
    }
};
