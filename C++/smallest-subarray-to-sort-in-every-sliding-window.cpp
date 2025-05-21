// Time:  O(n)
// Space: O(n)

// mono stack, two pointers
class Solution {
public:
    vector<int> minSubarraySort(vector<int>& nums, int k) {
        const int n = size(nums);
        const auto& count = [&](const auto& nums) {
            vector<int> nxt(n, n), stk;
            for (int i = n - 1; i >= 0; --i) {
                while (!(empty(stk) || nums[stk.back()] >= nums[i])) {
                    stk.pop_back();
                }
                if (!empty(stk)) {
                    nxt[i] = stk.back();
                }
                stk.emplace_back(i);
            }
            vector<int> result;
            for (int i = 1, j = 0, left = -1; i < n; ++i) {
                if (nums[i] < nums[i - 1]) {
                    left = i;
                }
                if (i < k - 1) {
                    continue;
                }
                j = max(j, i - (k - 1));
                while (!(nxt[j] > left)) {
                    j = nxt[j];  // or ++j
                }
                result.emplace_back(max(i - nxt[j] + 1, 0));
            }
            return result;
        };

        vector<int> result(n - k + 1);
        if (k == 1) {
            return result;
        }
        const auto& right = count(nums);
        for (int i = 0; i <= n - 1 - i; ++i) {
            tie(nums[i], nums[n - 1 - i]) = pair(-nums[n - 1 - i], -nums[i]);
        }
        const auto& left = count(nums);
        for (int i = 0; i < size(result); ++i) {
            result[i] = max(k - left[((n - k + 1) - 1) - i] - right[i], 0);
        }
        return result;
    }
};
