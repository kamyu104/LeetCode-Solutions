// Time:  O(n^2 * logn)
// Space: O(n)

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        unordered_map<int, int> dp = {{-1, 0}};
        for (const auto& i : arr1) {
            unordered_map<int, int> next_dp;
            for (const auto& [j, count] : dp) {
                if (i > j) {
                    if (!next_dp.count(i)) {
                        next_dp[i] = dp[j];
                    } else {
                        next_dp[i] = min(next_dp[i], dp[j]);
                    }
                }
                const auto& it = upper_bound(arr2.cbegin(), arr2.cend(), j);
                if (it != arr2.cend()) {
                    if (!next_dp.count(*it)) {
                        next_dp[*it] = dp[j] + 1;
                    } else {
                        next_dp[*it] = min(next_dp[*it], dp[j] + 1);
                    }
                }
            }
            dp = move(next_dp);
        }
        if (!dp.empty()) {
            return min_element(dp.cbegin(), dp.cend(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               })->second;
        }
        return -1;
    }
};
