// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        static const int MOD = 1e9 + 7;
        if (k == 1) {
            return maxSubKArray(arr, 1) % MOD;
        }
        return (maxSubKArray(arr, 2) +
                (k - 2) * max(accumulate(arr.cbegin(), arr.cend(), 0ll), 0ll)) % MOD;
    }

private:
    int maxSubKArray(const vector<int>& nums, int k) {
        int result = 0, curr = 0;
        for (int i = 0; i < k; ++i) {
            for (const auto& x : nums) {
                curr = max(curr + x, x);
                result = max(result, curr);
            }
        }
        return result;
    }
};
