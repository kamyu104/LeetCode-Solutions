// Time:  O(nlogn)
// Space: O(n)

// prefix sum, sorted list, binary search, mono stack
class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();

        vector<int> right(size(prices), NEG_INF);
        set<pair<int, int>> bst;
        for (int i = size(prices) - 1; i >= 0; --i) {
            const auto it = bst.lower_bound(pair(-prices[i], 0));
            if (it != begin(bst)) {
                right[i] = prev(it)->second;
            }
            if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(-prices[i], profits[i]);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        }
        int result = NEG_INF;
        bst.clear();
        for (int i = 0; i < size(prices); ++i) {
            const auto it = bst.lower_bound(pair(prices[i], 0));
            if (it != begin(bst)) {
                if (prev(it)->second != NEG_INF && right[i] != NEG_INF) {
                    result = max(result, prev(it)->second + profits[i] + right[i]);
                }
            }
            if (!(it == begin(bst) || prev(it)->second < profits[i])) {
                continue;
            }
            const auto [jt, _] = bst.emplace(prices[i], profits[i]);
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

// Time:  O(nlogn)
// Space: O(n)
// prefix sum, segment tree
class Solution3 {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();

        unordered_set<int> prices_set(cbegin(prices), cend(prices));
        vector<int> sorted_prices(cbegin(prices_set), cend(prices_set));;
        sort(begin(sorted_prices), end(sorted_prices));
        unordered_map<int, int> price_to_idx;
        for (int i = 0; i < size(sorted_prices); ++i) {
            price_to_idx[sorted_prices[i]] = i;
        }
        vector<int> right(size(prices), NEG_INF);
        SegmentTree st2(size(price_to_idx));
        for (int i = size(prices) - 1; i >= 0; --i) {
            right[i] = st2.query(price_to_idx[prices[i]] + 1, size(price_to_idx) - 1);
            st2.update(price_to_idx[prices[i]], profits[i]);
        }
        int result = NEG_INF;
        vector<int> left(size(prices), NEG_INF);
        SegmentTree st1(size(price_to_idx));
        for (int i = 0; i < size(prices); ++i) {
            const int left = st1.query(0, price_to_idx[prices[i]] - 1);
            if (left != NEG_INF && right[i] != NEG_INF) {
                result = max(result, left + profits[i] + right[i]);
            }
            st1.update(price_to_idx[prices[i]], profits[i]);
        }
        return result != NEG_INF ? result : -1;
    }

private:
    class SegmentTree {
    private:
        const int NEG_INF = numeric_limits<int>::min();
      
    public:
        explicit SegmentTree(int N)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2, NEG_INF),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {

        }

        void update(int i, int h) {
            int x = base + i;
            tree[x] = max(tree[x], h);
            while (x > 1) {
                x /= 2;
                tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        int query(int L, int R) {
            int result = NEG_INF;
            if (L > R) {
                return result;
            }
            L += base;
            R += base;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    result = max(result, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    result = max(tree[R], result);
                    --R;
                }
            }
            return result;
        }

        vector<int> tree;
        int base;
    };
};

// Time:  O(nlogn)
// Space: O(n)
// prefix sum, segment tree
class Solution4 {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        static const int NEG_INF = numeric_limits<int>::min();

        unordered_set<int> prices_set(cbegin(prices), cend(prices));
        vector<int> sorted_prices(cbegin(prices_set), cend(prices_set));;
        sort(begin(sorted_prices), end(sorted_prices));
        unordered_map<int, int> price_to_idx;
        for (int i = 0; i < size(sorted_prices); ++i) {
            price_to_idx[sorted_prices[i]] = i;
        }
        vector<int> left(size(prices), NEG_INF);
        SegmentTree st1(size(price_to_idx));
        for (int i = 0; i < size(prices); ++i) {
            left[i] = st1.query(0, price_to_idx[prices[i]] - 1);
            st1.update(price_to_idx[prices[i]], profits[i]);
        }
        vector<int> right(size(prices), NEG_INF);
        SegmentTree st2(size(price_to_idx));
        for (int i = size(prices) - 1; i >= 0; --i) {
            right[i] = st2.query(price_to_idx[prices[i]] + 1, size(price_to_idx) - 1);
            st2.update(price_to_idx[prices[i]], profits[i]);
        }
        int result = NEG_INF;
        for (int i = 0; i < size(profits); ++i) {
            if (left[i] != NEG_INF && right[i] != NEG_INF) {
                result = max(result, left[i] + profits[i] + right[i]);
            }
        }
        return result != NEG_INF ? result : -1;
    }

private:
    class SegmentTree {
    private:
        const int NEG_INF = numeric_limits<int>::min();
      
    public:
        explicit SegmentTree(int N)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2, NEG_INF),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {

        }

        void update(int i, int h) {
            int x = base + i;
            tree[x] = max(tree[x], h);
            while (x > 1) {
                x /= 2;
                tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        int query(int L, int R) {
            int result = NEG_INF;
            if (L > R) {
                return result;
            }
            L += base;
            R += base;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    result = max(result, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    result = max(tree[R], result);
                    --R;
                }
            }
            return result;
        }

        vector<int> tree;
        int base;
    };
};

