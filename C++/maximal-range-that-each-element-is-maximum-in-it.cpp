// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        vector<int> result(size(nums));
        vector<int> stk = {-1};
        nums.emplace_back(numeric_limits<int>::max());
        for (int i = 0; i < size(nums); ++i) {
            while (stk.back() != -1 && nums[stk.back()] < nums[i]) {
                const int j = stk.back(); stk.pop_back();
                result[j] = (i - 1) - stk.back();
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
