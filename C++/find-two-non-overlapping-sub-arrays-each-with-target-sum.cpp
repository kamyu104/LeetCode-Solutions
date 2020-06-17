// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> prefix = {{0, -1}};
        vector<int> dp(arr.size());
        int result = numeric_limits<int>::max(), min_len = numeric_limits<int>::max();
        int accu = 0;
        for (int right = 0; right < arr.size(); ++right) {
            accu += arr[right];
            prefix[accu] = right;
            if (prefix.count(accu - target)) {
                auto left = prefix[accu - target];
                min_len = min(min_len, right - left);
                if (left != -1 && dp[left] != numeric_limits<int>::max()) {
                    result = min(result, dp[left] + (right - left));
                }
            }
            dp[right] = min_len;
        }
        return result != numeric_limits<int>::max() ? result : -1;
    }
};
