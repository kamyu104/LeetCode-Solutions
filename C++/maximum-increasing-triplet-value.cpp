// Time:  O(nlogn)
// Space: O(n)

// bst, prefix sum
class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        set<int> left;
        vector<int> right(size(nums));
        for (int i = size(nums) - 2; i >= 1; --i) {
            right[i] = max(right[i + 1], nums[i + 1]);
        }
        int result = 0;
        for (int i = 1; i + 1 < size(nums); ++i) {
            left.emplace(nums[i - 1]);
            auto it = left.lower_bound(nums[i]);
            if (it != cbegin(left) && right[i] > nums[i]) {
                result = max(result, *prev(it) - nums[i] + right[i]);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bst
class Solution2 {
public:
    int maximumTripletValue(vector<int>& nums) {
        multiset<int> left, right(cbegin(nums) + 1, cend(nums));
        int result = 0;
        for (int i = 1; i + 1 < size(nums); ++i) {
            left.emplace(nums[i - 1]);
            right.erase(right.find(nums[i]));
            auto it = left.lower_bound(nums[i]);
            if (it != cbegin(left) && *rbegin(right) > nums[i]) {
                result = max(result, *prev(it) - nums[i] + *rbegin(right));
            }
        }
        return result;
    }
};
