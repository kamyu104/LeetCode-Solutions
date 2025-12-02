// Time:  O(n)
// Space: O(1)

// quick select
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (!k) {
            return size(nums);
        }
        nth_element(begin(nums), begin(nums) + (size(nums) - k), end(nums));
        int result = 0;
        for (int i = 0; i < size(nums) - k; ++i) {
            if (nums[i] < nums[size(nums) - k]) {
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    int countElements(vector<int>& nums, int k) {
        if (!k) {
            return size(nums);
        }
        ranges::sort(nums);
        int i = size(nums) - k - 1;
        for (; i >= 0; --i) {
            if (nums[i] < nums[size(nums) - k]) {
                break;
            }
        }
        return i + 1;
    }
};
