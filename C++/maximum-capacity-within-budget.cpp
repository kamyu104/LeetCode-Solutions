// Time:  O(n + b)
// Space: O(b)

// hash table, prefix sum
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        const auto& mid = (budget - 1) / 2;
        vector<int> lookup(budget);
        for (int i = 0; i < size(costs); ++i) {
            if (costs[i] >= budget) {
                continue;
            }
            lookup[costs[i]] = max(lookup[costs[i]], capacity[i]);
        }
        for (int i = 0; i + 1 <= mid; ++i) {
            lookup[i + 1] = max(lookup[i + 1], lookup[i]);
        }
        int result = 0, mx = 0;
        for (int i = 0; i < size(costs); ++i) {
            if (costs[i] > mid) {
                continue;
            }
            result = max(result, mx + capacity[i]);
            mx = max(mx, capacity[i]);
        }
        for (int i = mid + 1; i <= budget - 1; ++i) {
            result = max(result, lookup[i] + lookup[(budget - 1) - i]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, mono stack
class Solution2 {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<int> idxs(size(costs));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return costs[a] < costs[b];
        });

        int result = 0;
        vector<pair<int, int>> stk;
        for (const auto& i : idxs) {
            const auto& cost = costs[i], &cap = capacity[i];
            if (cost >= budget) {
                break;
            }
            while (!empty(stk) && stk.back().first + cost >= budget) {
                stk.pop_back();
            }
            result = max(result, (!empty(stk) ? stk.back().second : 0) + cap);
            if (empty(stk) || stk.back().second < cap) {
                stk.emplace_back(cost, cap);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, binary search
class Solution3 {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<int> idxs(size(costs));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return costs[a] < costs[b];
        });

        vector<int> prefix(size(capacity) + 1);
        for (int i = 0; i < size(capacity); ++i) {
            prefix[i + 1] = max(prefix[i], capacity[idxs[i]]);
        }
        int result = 0;
        vector<pair<int, int>> stk;
        vector<int> sorted_costs;
        sorted_costs.reserve(size(costs));
        for (const auto& i : idxs) {
            sorted_costs.emplace_back(costs[i]);
        }
        for (int i = 0; i < size(idxs); ++i) {
            const auto& cost = costs[idxs[i]], &cap = capacity[idxs[i]];
            if (cost >= budget) {
                break;
            }
            const auto& j = distance(cbegin(sorted_costs), lower_bound(cbegin(sorted_costs), cbegin(sorted_costs) + i, budget - cost)) - 1;
            result = max(result, prefix[j + 1] + cap);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, binary search
class Solution4 {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        const auto& binary_search_right = [](int left, int right, const auto& check) {
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

        vector<int> idxs(size(costs));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return costs[a] < costs[b];
        });

        vector<int> prefix(size(capacity) + 1);
        for (int i = 0; i < size(capacity); ++i) {
            prefix[i + 1] = max(prefix[i], capacity[idxs[i]]);
        }
        int result = 0;
        vector<pair<int, int>> stk;
        for (int i = 0; i < size(idxs); ++i) {
            const auto& cost = costs[idxs[i]], &cap = capacity[idxs[i]];
            if (cost >= budget) {
                break;
            }
            const auto& j = binary_search_right(0, i - 1, [&](const auto& x) {
                return costs[idxs[x]] + cost < budget;
            });
            result = max(result, prefix[j + 1] + cap);
        }
        return result;
    }
};
