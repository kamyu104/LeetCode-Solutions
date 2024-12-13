// Time:  O(n)
// Space: O(1)

// prefix sum, CodeChef Starters 146 - Bouncing Ball (https://www.codechef.com/problems/BOUNCE_BALL)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        for (int i = 0, curr = 0, total = accumulate(cbegin(nums), cend(nums), 0); i < size(nums); ++i) {
            if (nums[i] == 0) {
                result += max(2 - abs(curr - (total - curr)), 0);
            } else {
                curr += nums[i];
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum, CodeChef Starters 146 - Bouncing Ball (https://www.codechef.com/problems/BOUNCE_BALL)
class Solution2 {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> suffix(size(nums) + 1);
        for (int i = size(nums) - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] == 0) {
                result += max(2 - abs(prefix[i] - suffix[i + 1]), 0);
            }
        }
        return result;
    }
};
