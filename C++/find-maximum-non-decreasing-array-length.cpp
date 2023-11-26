// Time:  O(n)
// Space: O(n)

// greedy, prefix sum, mono stack, two pointers
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int64_t dp = 0, prefix = 0;
        vector<vector<int64_t>> stk = {{0, 0, 0}};
        for (int right = 0, left = 0; right < size(nums); ++right) {
            prefix += nums[right];
            for (; left + 1 < size(stk) && stk[left+1][0] <= prefix; ++left);
            const int last = prefix - stk[left][1];
            dp = stk[left][2] + 1;
            while (!empty(stk) && stk.back()[0] >= last + prefix) {
                stk.pop_back();
            }
            stk.push_back({last + prefix, prefix, dp});
            left = min(left, static_cast<int>(size(stk) - 1));
        }
        return dp;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// greedy, prefix sum, mono stack, binary search
class Solution2 {
public:
    int findMaximumLength(vector<int>& nums) {
        int64_t dp = 0, prefix = 0;
        vector<vector<int64_t>> stk = {{0, 0, 0}};
        for (int right = 0; right < size(nums); ++right) {
            prefix += nums[right];
            const int left = distance(cbegin(stk), lower_bound(cbegin(stk), cend(stk), vector<int64_t>{prefix+1, 0, 0})) - 1;
            const int last = prefix - stk[left][1];
            dp = stk[left][2] + 1;
            while (!empty(stk) && stk.back()[0] >= last + prefix) {
                stk.pop_back();
            }
            stk.push_back({last + prefix, prefix, dp});
        }
        return dp;
    }
};
