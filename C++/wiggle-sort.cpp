// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (((i % 2) && nums[i] < nums[i - 1]) ||
                (!(i % 2) && nums[i] > nums[i - 1])) {
                // Swap unordered elements.
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};


class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int pre = nums[0];
        bool inc = true;
        for (int i = 1; i < nums.size(); ++i) {
            if ((inc && pre <= nums[i]) ||
                (!inc && pre >= nums[i])) {
                nums[i - 1] = pre;
                pre = nums[i];
            } else {
                nums[i - 1] = nums[i];
            }
            inc = !inc;
        }
        nums.back() = pre;
    }
};
