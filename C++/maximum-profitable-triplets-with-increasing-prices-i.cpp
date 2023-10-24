// Time:  O(nlogn)
// Space: O(n)

// prefix sum, sorted list, binary search, mono stack
class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();
        vector<int> left(size(prices), NEG_INF);
        set<pair<int, int>> bst;
        for (int i = 0; i < size(prices); ++i) {
            const auto it = bst.lower_bound(pair(prices[i], 0));
            if (it != begin(bst)) {
                left[i] = prev(it)->second;
            }
            if (it != end(bst) && it->first == prices[i]) {
                if (!(it->second < profits[i])) {
                    continue;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(prices[i], profits[i]);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        }
        int result = NEG_INF;
        bst.clear();
        for (int i = size(prices) - 1; i >= 0; --i) {
            const auto it = bst.lower_bound(pair(-prices[i], 0));
            if (it != begin(bst)) {
                if (left[i] != NEG_INF && prev(it)->second != NEG_INF) {
                    result = max(result, left[i] + profits[i] + prev(it)->second);
                }
            }
            if (it != end(bst) && -it->first == prices[i]) {
                if (!(it->second < profits[i])) {
                    continue;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(-prices[i], profits[i]);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        }
        return result != NEG_INF ? result : -1;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// prefix sum, sorted list, binary search, mono stack
class Solution2 {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();
        vector<int> left(size(prices), NEG_INF);
        set<pair<int, int>> bst;
        for (int i = 0; i < size(prices); ++i) {
            const auto it = bst.lower_bound(pair(prices[i], 0));
            if (it != begin(bst)) {
                left[i] = prev(it)->second;
            }
            if (it != end(bst) && it->first == prices[i]) {
                if (!(it->second < profits[i])) {
                    continue;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(prices[i], profits[i]);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        }
        vector<int> right(size(prices), NEG_INF);
        bst.clear();
        for (int i = size(prices) - 1; i >= 0; --i) {
            const auto it = bst.lower_bound(pair(-prices[i], 0));
            if (it != begin(bst)) {
                right[i] = prev(it)->second;
            }
            if (it != end(bst) && -it->first == prices[i]) {
                if (!(it->second < profits[i])) {
                    continue;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(-prices[i], profits[i]);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        }
        int result = NEG_INF;
        for (int i = 0; i < size(profits); ++i) {
            if (left[i] != NEG_INF && right[i] != NEG_INF) {
                result = max(result, left[i] + profits[i] + right[i]);
            }
        }
        return result != NEG_INF ? result : -1;
    }
};
