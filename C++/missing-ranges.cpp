// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        for (int i = 0, pre = lower - 1, cur = 0; i <= nums.size(); ++i, pre = cur) {
            if (i == nums.size()) {
                cur = upper + 1;
            } else {
                cur = nums[i];
            }
            if (cur - pre >= 2) {
                ranges.emplace_back(getRange(pre + 1, cur - 1));
            }
        }
        return ranges;
    }

    string getRange(const int lower, const int upper) {
        if (lower == upper) {
            return to_string(lower);
        } else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};
