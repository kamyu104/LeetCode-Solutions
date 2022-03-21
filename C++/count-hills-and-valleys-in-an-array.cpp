// Time:  O(n)
// Space: O(1)

// simulation, array
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0, inc = -1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] < nums[i + 1]) {
                result += (inc == 0) ? 1 : 0;
                inc = 1;
            } else if (nums[i] > nums[i + 1]) {
                result += (inc == 1) ? 1 : 0;
                inc = 0;
            }
        }
        return result;
    }
};
