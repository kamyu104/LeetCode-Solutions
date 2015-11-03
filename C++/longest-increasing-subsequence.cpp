// Time:  O(nlogn)
// Space: O(n)

// Binary search solution with STL.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        // Find the first index "left" which satisfies LIS[left] >= target
        auto it = lower_bound(LIS->begin(), LIS->end(), target);

        // If not found, append the target.
        if (it != LIS->end()) {
            *it = target;
        } else {
            LIS->emplace_back(target);
        }
    }
};

// Binary search solution.
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        int left = 0, right = LIS->size() - 1;
        auto comp = [](int x, int target) { return x >= target; };

        // Find the first index "left" which satisfies LIS[left] >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comp((*LIS)[mid], target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If not found, append the target.
        if (left == LIS->size()) {
            LIS->emplace_back(target);
        } else {
            (*LIS)[left] = target;
        }
    }
};

// Time:  O(n^2)
// Space: O(n)
// Traditional DP solution.
class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);  // dp[i]: the length of LIS ends with nums[i]
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
