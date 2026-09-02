// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            if (!(i + 1 == size(nums) || nums[i + 1] != nums[i])) {
                continue;
            }
            if (cnt[nums[i]] == 0) {
                ++result;
            } else if (cnt[nums[i]] == 1) {
                --result;
            }
            ++cnt[nums[i]];
        }
        return result;
    }
};
