// Time:  O(n)
// Space: O(n)

// dp, greedy, prefix sum, mono stack, two pointers
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int dp = 0;
        int64_t prefix = 0;
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

// Time:  O(n)
// Space: O(n)
// dp, greedy, prefix sum, mono deque
class Solution2 {
public:
    int findMaximumLength(vector<int>& nums) {
        int dp = 0;
        int64_t prefix = 0, prev_prefix = 0, prev_dp = 0;;
        deque<vector<int64_t>> dq;
        for (int right = 0; right < size(nums); ++right) {
            prefix += nums[right];
            for (; !empty(dq) && dq.front()[0] <= prefix; dq.pop_front()) {
                prev_prefix = dq.front()[1];
                prev_dp = dq.front()[2];
            }
            const int last = prefix - prev_prefix;
            dp = prev_dp + 1;
            while (!empty(dq) && dq.back()[0] >= last + prefix) {
                dq.pop_back();
            }
            dq.push_back({last + prefix, prefix, dp});
        }
        return dp;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// dp, greedy, prefix sum, mono stack, binary search
class Solution3 {
public:
    int findMaximumLength(vector<int>& nums) {
        int dp = 0;
        int64_t prefix = 0;
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

// Time:  O(nlogn)
// Space: O(n)
// dp, greedy, prefix sum, binary search
class Solution4 {
public:
    int findMaximumLength(vector<int>& nums) {
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int64_t> dp(size(nums) + 1, numeric_limits<int>::max());
        dp[0] = 0;
        vector<int> prev(size(nums) + 1, -1);
        for (int right = 0, left = -1; right < size(nums); ++right) {
            left = max(left, prev[right]);
            dp[right + 1] = dp[left + 1] + 1;
            const int next_right = distance(cbegin(prefix), lower_bound(cbegin(prefix), cend(prefix), prefix[right + 1] + (prefix[right + 1] - prefix[left + 1]))) - 1;
            prev[next_right] = right;
        }
        return dp.back();
    }
};

