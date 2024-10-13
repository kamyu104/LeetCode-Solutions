// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result(size(nums), -1);
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] & 1) {
                result[i] = nums[i] - (((nums[i] + 1) & (~nums[i])) >> 1);
            }
        }
        return result;
    }
};

// Time:  O(n * r)
// Space: O(1)
// brute force
class Solution2 {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result(size(nums), -1);
        for (int i = 0; i < size(nums); ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                if ((j | (j + 1)) == nums[i]) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};
