// Time:  O(n^2 * logn)
// Space: O(n)

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        std::sort(arr2.begin(), arr2.end());
        arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());
        unordered_map<int, int> dp = {{0, arr1[0]}, {1, arr2[0]}};
        for (int i = 1; i < arr1.size(); ++i) {
            unordered_map<int, int> next_dp;
            for (const auto& [j, count] : dp) {
                if (dp[j] < arr1[i]) {
                    if (!next_dp.count(j)) {
                        next_dp[j] = arr1[i];
                    } else {
                        next_dp[j] = min(next_dp[j], arr1[i]);
                    }
                }
                const auto& it = upper_bound(arr2.cbegin(), arr2.cend(), dp[j]);
                if (it != arr2.cend()) {
                    if (!next_dp.count(j + 1)) {
                        next_dp[j + 1] = *it;
                    } else {
                        next_dp[j + 1] = min(next_dp[j + 1], *it);
                    }
                }
            }
            dp = move(next_dp);
        }
        if (dp.empty()) {
            return -1;
        }
        return min_element(dp.cbegin(), dp.cend())->first;
    }
};
