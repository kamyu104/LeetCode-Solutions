// Time:  O((n + q) *logn)
// Space: O(n)

// sort, binary search, greedy, prefix sum
class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        const auto& binary_search = [&](int k, int m) {
            const auto& check = [&](int x) {
                return k - (prices[size(prices) - x] - k) <= prices[((m - x) + 1) - 1] - 0;
            };

            int left = 1, right = m;
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        sort(begin(prices), end(prices));
        vector<long long> prefix(size(prices) + 1);
        for (int i = 0; i < size(prices); ++i) {
            prefix[i + 1] = prefix[i] + prices[i];
        }
        vector<long long> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& k = queries[i][0], &m = queries[i][1];
            const long long cnt = binary_search(k, m);
            const auto& a = prefix[size(prices)] - prefix[size(prices) - cnt] - cnt * k;
            const auto& b = prefix[m - cnt] + cnt * k;
            result[i] = b - a;
        }
        return result;
    }
};
