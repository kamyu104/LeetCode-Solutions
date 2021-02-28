// Time:  O(m * max(max_base, target + max_topping / 2)) ~= O(m * t)
// Space: O(max(max_base, target + max_topping / 2)) ~= O(t)

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        static const int MAX_COUNT = 2;

        const auto max_base = *max_element(cbegin(baseCosts), cend(baseCosts));
        const auto max_topping = *max_element(cbegin(toppingCosts), cend(toppingCosts));
        vector<bool> dp(max(max_base, target + max_topping / 2) + 1);
        for (const auto& b : baseCosts) {
            dp[b] = true;
        }
        for (const auto& t : toppingCosts) {
            for (int count = 0; count < MAX_COUNT; ++count) {
                for (int i = size(dp) - 1 - t; i >= 1; --i) {
                    if (dp[i]) {
                        dp[i + t] = true;
                    }
                }
            }
        }
        int result = numeric_limits<int>::max();
        for (int i = 1; i <= size(dp) - 1; ++i) {
            if (!dp[i]) {
                continue;
            }
            if (abs(i - target) < abs(result - target)) {
                result = i;
            }
            if (i >= target) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(n * 3^m)
// Space: O(m * t)
class Solution2 {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        unordered_map<int, unordered_set<int>> lookup;
        int result = numeric_limits<int>::max();
        for (const auto& b : baseCosts) {
            backtracking(toppingCosts, 0, b, target, &lookup, &result);
        }
        return result;
    }

private:
    void backtracking(const vector<int>& toppingCosts,
                      int i, int cost, int target,
                      unordered_map<int, unordered_set<int>> *lookup,
                      int *result) {

        static const int max_top = 2;
        if (lookup->count(i) && (*lookup)[i].count(cost)) {
            return;
        }
        (*lookup)[i].emplace(cost);
        if (cost >= target || i == size(toppingCosts)) {
            if (pair(abs(cost - target), cost) < pair(abs(*result - target), *result)) {
                *result = cost;
            }
            return;
        }
        for (int j = 0; j <= max_top; ++j) {
            backtracking(toppingCosts, i + 1, cost + j * toppingCosts[i], target, lookup, result);
        }
    }
};

// Time:  O(3^m*log(3^m)) + O(n*log(3^m)) = O(m*(3^m + n))
// Space: O(3^m)
class Solution3 {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        static const int MAX_COUNT = 2;

        unordered_set<int> combs_set = {0};
        for (const auto& t : toppingCosts) {
            unordered_set<int> new_combs_set;
            for (const auto& c : combs_set) {
                for (int i = 0; i <= MAX_COUNT; ++i) {
                    new_combs_set.emplace(c + i * t);
                }
            }
            combs_set = move(new_combs_set);
        }
        vector<int> combs(cbegin(combs_set), cend(combs_set));
        sort(begin(combs), end(combs));
        int result = numeric_limits<int>::max();
        for (const auto& b : baseCosts) {
            const auto& cit = lower_bound(cbegin(combs), cend(combs), target - b);
            if (cit != cend(combs)) {
                if (pair(abs(b + *cit - target), b + *cit) < pair(abs(result - target), result)) {
                    result = b + *cit;
                }
            }
            if (cit != cbegin(combs)) {
                if (pair(abs(b + *prev(cit) - target), b + *prev(cit)) < pair(abs(result - target), result)) {
                    result = b + *prev(cit);
                }
            }
        }
        return result;
    }
};

// Time:  O(n * 3^m)
// Space: O(3^m)
class Solution4 {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        static const int MAX_COUNT = 2;

        unordered_set<int> combs_set = {0};
        for (const auto& t : toppingCosts) {
            unordered_set<int> new_combs_set;
            for (const auto& c : combs_set) {
                for (int i = 0; i <= MAX_COUNT; ++i) {
                    new_combs_set.emplace(c + i * t);
                }
            }
            combs_set = move(new_combs_set);
        }
        int result = numeric_limits<int>::max();
        for (const auto& b : baseCosts) {
            for (const auto& c : combs_set) {
                if (pair(abs(b + c - target), b + c) < pair(abs(result - target), result)) {
                    result = b + c;
                }
            }
        }
        return result;
    }
};
