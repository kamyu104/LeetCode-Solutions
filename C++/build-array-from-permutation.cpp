// Time:  O(n)
// Space: O(1)

// inplace solution
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            for (int prev = i, curr = nums[i];
                 curr >= 0 && curr != i;
                 tie(prev, curr) = pair(curr, ~nums[prev])) {
                tie(nums[prev], nums[curr]) = pair(~nums[curr], (prev == i) ? ~nums[prev] : nums[prev]);
            }
        }
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] < 0) {
                nums[i] = ~nums[i];
            }
        }
        return nums;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};
