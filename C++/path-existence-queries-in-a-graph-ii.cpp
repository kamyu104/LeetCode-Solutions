// Time:  O((n + q) * logn)
// Space: O(nlogn)

// prefix sum, greedy, binary lifting
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const auto& ceil_log2_x = [&](int x) {
            return bit_length(x - 1);
        };

        vector<int> sorted_i(n);
        iota(begin(sorted_i), end(sorted_i), 0);
        sort(begin(sorted_i), end(sorted_i), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> i_to_idx(n);
        for (int idx = 0; idx < n; ++idx) {
            i_to_idx[sorted_i[idx]] = idx;
        }
        vector<int> prefix(n);
        for (int i = 0; i < n - 1; ++i) {
            prefix[i + 1] = prefix[i] + (nums[sorted_i[i + 1]] - nums[sorted_i[i]] <= maxDiff ? 0 : 1);
        }
        vector<vector<int>> P(ceil_log2_x(n - 1) + 1, vector<int>(n, n - 1));
        for (int right = 0, left = 0; right < n; ++right) {
            for (; nums[sorted_i[right]] - nums[sorted_i[left]] > maxDiff; ++left) {
                P[0][left] = right - 1;
            }
        }
        for (int i = 0; i + 1 < size(P); ++i) {
            for (int j = 0; j < n; ++j) {
                P[i + 1][j] = P[i][P[i][j]];
            }
        }
        vector<int> result(size(queries), -1);
        for (int idx = 0; idx < size(queries); ++idx) {
            int i = queries[idx][0], j = queries[idx][1];
            if (i == j) {
                result[idx] = 0;
                continue;
            }
            if (prefix[i_to_idx[i]] != prefix[i_to_idx[j]]) {
                continue;
            }
            if (i_to_idx[i] > i_to_idx[j]) {
                swap(i, j);
            }
            int curr = i_to_idx[i], l = 0;
            for (int k = size(P) - 1; k >= 0; --k) {
                if (P[k][curr] < i_to_idx[j]) {
                    curr = P[k][curr];
                    l += 1 << k;
                }
            }
            result[idx] = l + 1;
        }
        return result;
    }
};
