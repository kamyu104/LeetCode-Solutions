// Time:  O(n^2 * logn)
// Space: O(n)

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        std::sort(arr2.begin(), arr2.end());
        arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());
        unordered_map<int, int> dp = {{0, arr1[0]}, {1, arr2[0]}};  // dp[min_cost] = end_with_val
        for (int i = 1; i < arr1.size(); ++i) {
            unordered_map<int, int> next_dp;
            for (const auto& [cost, val] : dp) {
                if (val < arr1[i]) {
                    if (!next_dp.count(cost)) {
                        next_dp[cost] = arr1[i];
                    } else {
                        next_dp[cost] = min(next_dp[cost], arr1[i]);
                    }
                }
                const auto& it = upper_bound(arr2.cbegin(), arr2.cend(), val);
                if (it != arr2.cend()) {
                    if (!next_dp.count(cost + 1)) {
                        next_dp[cost + 1] = *it;
                    } else {
                        next_dp[cost + 1] = min(next_dp[cost + 1], *it);
                    }
                }
            }
            dp = move(next_dp);
            if (dp.empty()) {
                return -1;
            }
        }
        return min_element(dp.cbegin(), dp.cend())->first;
    }
};
