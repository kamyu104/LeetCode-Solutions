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

// Time:  O(n)
// Space: O(1)
// greedy
class Solution2 {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        const auto& check = [&](int target) {
            int parity = 0;
            for (int i = 0, cnt = 0; i < size(nums); ++i) {
                if (nums[i] == target) {
                    continue;
                }
                cnt += parity ? i : -i;
                if (cnt > k) {
                    return false;
                }
                parity ^= 1;
            }
            return parity == 0;
        };

        return check(1) || check(-1);
    }
};
