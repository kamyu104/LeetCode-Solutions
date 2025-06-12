// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        const auto& check = [&](int target) {
            for (int i = 0, cnt = 0, sign = 1; i < size(nums); ++i) {
                if (nums[i] * sign == target) {
                    sign = 1;
                    continue;
                }
                if (i + 1 == size(nums) || ++cnt > k) {
                    return false;
                }
                sign = -1;
            }
            return true;
        };

        return check(1) || check(-1);
    }
};
