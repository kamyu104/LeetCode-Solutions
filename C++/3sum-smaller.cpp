// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (nums[i] + nums[j] + nums[k] >= target) {
                    --j;
                } else {
                    count += j - i;
                    ++i;
                }
            }
        }

        return count;
    }
};
