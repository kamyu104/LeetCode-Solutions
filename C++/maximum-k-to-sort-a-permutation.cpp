// Time:  O(n)
// Space: O(1)

// sort, constructive algorithms
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int result = -1;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] == i) {
                continue;
            }
            result = result != -1 ? result & i : i;
        }
        return result != -1 ? result : 0;
    }
};
