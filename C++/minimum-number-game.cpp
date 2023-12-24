// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = 0; i < size(nums); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};
