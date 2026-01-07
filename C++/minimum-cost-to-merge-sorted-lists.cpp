// Time:  O(l * nlogn + 2^n * log(n * l) * n * logl + 3^n), n = len(lists), l = max(len(list) for list in lists)
// Space: O(n * l + 2^n)

// dp, sort, heap, binary search, submask enumeration
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& merge = [](const auto& lists) {
            using T = tuple<int, int, int>;
            vector<T> data;
            data.reserve(size(lists));
            for (int i = 0; i < size(lists); ++i) {
                data.emplace_back(lists[i][0], i, 0);
            }
            priority_queue<T, vector<T>, greater<T>> min_heap(cbegin(data), cend(data));
            vector<int> result;
            while (!empty(min_heap)) {
                const auto [x, i, j] = min_heap.top(); min_heap.pop();
                result.emplace_back(x);
                if (j + 1 < size(lists[i])) {
                    min_heap.emplace(lists[i][j + 1], i, j + 1);
                }
            }
            return result;
        };

        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }; 

        vector<int> dp1(1 << size(lists));
        for (int i = 0; i < size(lists); ++i) {  // Time: O(2^n)
            dp1[1 << i] = size(lists[i]);
        }
        for (int mask = 1; mask < size(dp1); ++mask) {  // Time: O(2^n)
            dp1[mask] = dp1[mask ^ (mask & -mask)] + dp1[mask & -mask];
        }
        auto sorted_vals = merge(lists);  // Time: O((n * l) * logn)
        sorted_vals.erase(unique(begin(sorted_vals), end(sorted_vals)), end(sorted_vals));
        vector<int> dp2(1 << size(lists));
        for (int mask = 1; mask < size(dp2); ++mask) {  // Time: O(2^n * log(n * l) * n * logl)
            const auto& check = [&](int x) {
                int cnt = 0;
                for (int i = 0; i < size(lists); ++i) {
                    if ((mask & (1 << i)) == 0) {
                        continue;
                    }
                    cnt += distance(cbegin(lists[i]), upper_bound(cbegin(lists[i]), cend(lists[i]), sorted_vals[x]));
                }
                return cnt >= (dp1[mask] + 1) / 2;
            };

            dp2[mask] = sorted_vals[binary_search(0, size(sorted_vals) - 1, check)];
        }
        vector<int64_t> dp3(1 << size(lists));
        for (int mask = 1; mask < size(dp3); ++mask) {  // Time: O(3^n)
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            dp3[mask] = INF;
            for (int submask = (mask - 1) & mask; submask > (mask ^ submask); submask = (submask - 1) & mask) {
                dp3[mask] = min(dp3[mask], dp3[submask] + dp3[mask ^ submask] + abs(dp2[submask] - dp2[mask ^ submask]) + dp1[mask]);
            }
        }
        return dp3.back();
    }
};
