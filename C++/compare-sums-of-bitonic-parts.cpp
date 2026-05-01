// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int64_t total = 0;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] < nums[i + 1]) {
                total += nums[i];
            } else if (nums[i] > nums[i + 1]) {
                total -= nums[i + 1];
            }
        }
        return total > 0 ? 0 : (total < 0 ? 1 : -1);
    }
};
