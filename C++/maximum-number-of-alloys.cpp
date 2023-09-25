// Time:  O(k * nlogn)
// Space: O(n)

// sort, math
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        static const int INF = numeric_limits<int>::max();
        const auto& count = [&](const vector<int>& machine, int budget) {
            const auto& cnt = [&](int x) {
                return stock[x] / machine[x];
            };
        
            vector<int> idxs(n);
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
                return cnt(a) < cnt(b);
            });
            
            int result = cnt(idxs[0]);
            for (int i = 0, prefix = 0, curr = 0, discount = 0; i < n; ++i) {
                curr += cost[idxs[i]] * machine[idxs[i]];
                discount += cost[idxs[i]] * (stock[idxs[i]] % machine[idxs[i]]);
                if (i + 1 != n && cnt(idxs[i + 1]) - cnt(idxs[i]) == 0) {
                    continue;
                }
                prefix += curr;
                budget += discount;
                curr = discount = 0;
                const auto mn = min(i + 1 < n ? (cnt(idxs[i + 1]) - cnt(idxs[i])) : INF, budget / prefix);
                if (mn == 0) {
                    break;
                }
                budget -= prefix * mn;
                result += mn;
            }
            return result;
        };

        int result = 0;
        for (const auto& machine : composition) {
            result = max(result, count(machine, budget));
        }
        return result;
    }
};

// Time:  O(k * n * logr), r = min(stock)+budget
// Space: O(1)
// binary search
class Solution2 {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        const auto& check = [&](int64_t x) {
            for (const auto& machine : composition) {
                int64_t curr = 0;
                for (int i = 0; i < n; ++i) {
                    curr += (max(x * machine[i] - stock[i], static_cast<int64_t>(0)) * cost[i]);
                    if (curr > budget) {
                        break;
                    }
                }
                if (curr <= budget) {
                    return true;
                }
            }
            return false;
        };

        int left = 1, right = *min_element(cbegin(stock), cend(stock)) + budget;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
