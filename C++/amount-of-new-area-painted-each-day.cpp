// Time:  O(nlogr), r is the max position
// Space: O(r)

template <typename T>
class SegmentTree {
 public:
    explicit SegmentTree(
        int N,
        const function<T(const T&, const T&)>& query_fn,
        const function<T(const T&, const T&)>& update_fn)
      : base_(N),
        tree_(2 * N),
        lazy_(2 * N),
        count_(2 * N, 1),
        query_fn_(query_fn),
        update_fn_(update_fn) {
        H_ = 1;
        while ((1 << H_) < N) {
            ++H_;
        }
        for (int i = N - 1; i >= 1; --i) {
            count_[i] = count_[2 * i] + count_[2 * i + 1];
        }
    }

    void update(int L, int R, const T& val) {
        L += base_;
        R += base_;
        push(L);  // key point
        push(R);  // key point
        int L0 = L, R0 = R;
        for (; L <= R; L >>= 1, R >>= 1) {
            if ((L & 1) == 1) {
                apply(L++, val);
            }
            if ((R & 1) == 0) {
                apply(R--, val);
            }
        }
        pull(L0);
        pull(R0);
    }

    T query(int L, int R) {
        T result{};
        if (L > R) {
            return result;
        }
        L += base_;
        R += base_;
        push(L);
        push(R);
        for (; L <= R; L >>= 1, R >>= 1) {
            if ((L & 1) == 1) {
                result = query_fn_(result, tree_[L++]);
            }
            if ((R & 1) == 0) {
                result = query_fn_(result, tree_[R--]);
            }
        }
        return result;
    }

 private:
    void apply(int x, const T val) {
        tree_[x] = update_fn_(tree_[x], val * count_[x]);
        if (x < base_) {
            lazy_[x] = update_fn_(lazy_[x], val);
        }
    }

    void pull(int x) {
        while (x > 1) {
            x >>= 1;
            tree_[x] = query_fn_(tree_[x * 2], tree_[x * 2 + 1]);
            if (lazy_[x]) {
                tree_[x] = update_fn_(tree_[x], lazy_[x] * count_[x]);
            }
        }
    }

    void push(int x) {
       for (int h = H_; h > 0; --h) {
           int y = x >> h;
           if (lazy_[y]) {
                apply(y * 2, lazy_[y]);
                apply(y * 2 + 1, lazy_[y]);
                lazy_[y] = 0;
            }
        }
    }

    int base_;
    int H_;
    vector<T> tree_;
    vector<T> lazy_;
    vector<T> count_;
    const function<T(const T&, const T&)> query_fn_;
    const function<T(const T&, const T&)> update_fn_;
};

// segment tree
class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        const auto& query = [] (const auto& x, const auto& y) {
            return x + y;
        };
        const auto& update = [] (const auto& x, const auto& y) {
            return y;
        };
        const int max_pos = (*max_element(cbegin(paint), cend(paint),
            [](const auto& x, const auto& y) { return x[1] < y[1]; }
        ))[1];
        SegmentTree<int> st(max_pos, query, update);
        vector<int> result;
        for (const auto& x : paint) {
            const int cnt = st.query(x[0], x[1] - 1);
            st.update(x[0], x[1] - 1, 1);
            result.emplace_back(st.query(x[0], x[1] - 1) - cnt);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// line sweep, heap
class Solution2 {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, vector<pair<int, int>>> points;
        for (int i = 0; i < size(paint); ++i) {
            points[paint[i][0]].emplace_back(1, i);
            points[paint[i][1]].emplace_back(0, i);
        }
        priority_queue<int, vector<int>, greater<int>> min_heap;
        vector<bool> lookup(size(paint));
        vector<int> result(size(paint));
        int prev = -1;
        for (const auto& [pos, v] : points) {
             while (!empty(min_heap) && lookup[min_heap.top()]) {
                min_heap.pop();
            }
            if (!empty(min_heap)) {
                result[min_heap.top()] += pos - prev;
            }
            prev = pos;
            for (const auto& [t, i] : v) {
                if (t) {
                    min_heap.emplace(i);
                } else {
                    lookup[i] = true;
                }
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// line sweep, bst
class Solution3 {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, vector<pair<int, int>>> points;
        for (int i = 0; i < size(paint); ++i) {
            points[paint[i][0]].emplace_back(1, i);
            points[paint[i][1]].emplace_back(0, i);
        }
        set<int> bst;
        vector<int> result(size(paint));
        int prev = -1;
        for (const auto& [pos, v] : points) {
            if (!empty(bst)) {
                result[*begin(bst)] += pos - prev;
            }
            prev = pos;
            for (const auto& [t, i] : v) {
                if (t) {
                    bst.emplace(i);
                } else {
                    bst.erase(i);
                }
            }            
        }
        return result;
    }
};
