// Time : O(nlogn), n is the value of the target
// Space: O(n)

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1);
        for (int i = 1; i <= target; ++i) {
            int k = bitLength(i);
            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }
            dp[i] = dp[(1 << k) - 1 - i] + k + 1;
            for (int j = 0; j < k; ++j) {
                dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k + j + 1);
            }
        }
        return dp.back();
    }

private:
    uint32_t bitLength(uint32_t n) {
        uint32_t left = 1, right = 32;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if ((1 << mid) > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
