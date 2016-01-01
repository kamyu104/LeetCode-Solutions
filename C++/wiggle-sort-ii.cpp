// Time:  O(n)
// Space: O(n)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int n = nums.size();
        int mid = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        dutchFlagSort(nums, nums[mid]);

        vector<int> res(n);
        for (int i = 0, smallEnd = mid;  i < n; i += 2, --smallEnd) {
            res[i] = nums[smallEnd];
        }
        for (int i = 1, largeEnd = n - 1; i < n; i += 2, --largeEnd) {
            res[i] = nums[largeEnd];
        }
        nums = res;
    }

    void dutchFlagSort(vector<int>& nums, int val) {
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
            if (nums[j] < val) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] > val) {
                swap(nums[j], nums[n--]);
            } else {
                ++j;
            }
        }
    }
};
