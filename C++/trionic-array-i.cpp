// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
     bool isTrionic(vector<int>& nums) {
        int p = 0;
        while (p + 1 < size(nums) && nums[p] < nums[p + 1]) {
            ++p;
        }
        int q = p;
        while (q + 1 < size(nums) && nums[q] > nums[q + 1]) {
            ++q;
        }
        int i = q;
        while (i + 1 < size(nums) && nums[i] < nums[i + 1]) {
            ++i;
        }
        return (0 < p && p < q && q < i && i == size(nums) - 1);
    }
};
