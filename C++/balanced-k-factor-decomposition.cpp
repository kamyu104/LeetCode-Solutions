// Time:  precompute: O(rlogr)
//        runtime:    O(k * (logn)^(k - 1))
// Space: O(rlogr)

// backtracking, number theory
const auto& factors = [](int n) {
    vector<vector<int>> result(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            result[j].emplace_back(i);
        }
    }
    return result;
};

const int MAX_N = 1e5;
const auto& FACTORS = factors(MAX_N);
class Solution {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> result, curr;
        function<void (int)> backtracking = [&](int remain) {
            const int start = !empty(curr) ? curr.back() : 1;
            if (size(curr) == k - 1) {
                if (remain >= start) {
                    curr.emplace_back(remain);
                    if (empty(result) || result.back() - result[0] > curr.back() - curr[0]) {
                        result = curr;
                    }
                    curr.pop_back();
                }
                return;
            }
            const auto& factors = FACTORS[remain];
            for (auto it = lower_bound(cbegin(factors), cend(factors), start); it != cend(factors); ++it) {
                curr.emplace_back(*it);
                backtracking(remain / *it);
                curr.pop_back();
            }
        };

        backtracking(n);
        return result;
    }
};

// Time:  O(k * (n^(1/2) * n^(1/4) * n^(1/8) * n^(1/6) + n^(1/2) * n^(1/4) * n^(1/8) + n^(1/2) * n^(1/4) + n^(1/2))) <= O(k^2 * n)
// Space: O(k)
// backtracking, number theory
class Solution2 {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> result, curr;
        function<void (int)> backtracking = [&](int remain) {
            const int start = !empty(curr) ? curr.back() : 1;
            if (size(curr) == k - 1) {
                if (remain >= start) {
                    curr.emplace_back(remain);
                    if (empty(result) || result.back() - result[0] > curr.back() - curr[0]) {
                        result = curr;
                    }
                    curr.pop_back();
                }
                return;
            }
            for (int i = 1; i * i <= remain; ++i) {
                if (remain % i) {
                    continue;
                }
                const int j = remain / i;
                if (i >= start) {
                    curr.emplace_back(i);
                    backtracking(j);
                    curr.pop_back();
                }
                if (j == i) {
                    continue;
                }
                if (j >= start) {
                    curr.emplace_back(j);
                    backtracking(i);
                    curr.pop_back();
                }
            }
        };

        backtracking(n);
        return result;
    }
};

// Time:  O(2^(k-1) * k * n)
// Space: O(k)
// backtracking, number theory
class Solution3 {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> result, curr;
        function<void (int)> backtracking = [&](int remain) {
            if (size(curr) == k - 1) {
                curr.emplace_back(remain);
                if (empty(result) || ranges::max(result) - ranges::min(result) > ranges::max(curr) - ranges::min(curr)) {
                    result = curr;
                }
                curr.pop_back();
                return;
            }
            for (int i = 1; i * i <= remain; ++i) {
                if (remain % i) {
                    continue;
                }
                const int j = remain / i;
                curr.emplace_back(i);
                backtracking(j);
                curr.pop_back();
                if (j == i) {
                    continue;
                }
                curr.emplace_back(j);
                backtracking(i);
                curr.pop_back();
            }
        };

        backtracking(n);
        return result;
    }
};
