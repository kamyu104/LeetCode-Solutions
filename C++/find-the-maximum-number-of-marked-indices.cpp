// Time:  O(nlogn)
// Space: O(1)

// sort, greedy, two pointers
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int left = 0;
        for (int right = (size(nums) + 1) / 2; right < size(nums); ++right) {
            if (2 * nums[left] <= nums[right]) {
                ++left;
            }
        }
        return left * 2;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, greedy, two pointers
class Solution2 {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int right = size(nums) - 1;
        for (int left = size(nums) - 1; left >= 0; --left) {
            if (2 * nums[left] <= nums[right]) {
                --right;
            }
        }
        return min(((size(nums) - 1) - right), size(nums) / 2) * 2;
    }
};
