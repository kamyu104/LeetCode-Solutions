// Time:  ctor:    O(n)
//        gather:  O(logn)
//        scatter: O(logn), amortized
// Space: O(n)

// design, segment tree, binary search, optimized from bookmyshow2
class BookMyShow {
public:
    BookMyShow(int n, int m)
      : st_(n, m)
      , m_(m)
      , i_(0) {
    }
    
    vector<int> gather(int k, int maxRow) {
        int i = 1;
        if (k > st_.tree[i][0]) {
            return {};
        }
        while (i < st_.base) {
            i = 2 * i + static_cast<int>(st_.tree[2 * i][0] < k);
        }
        if (i - st_.base > maxRow) {
            return {};
        }
        int cnt = st_.tree[i][0];
        int c = m_ - cnt;
        i -= st_.base;
        st_.update(i, vector<int64_t>(2, cnt - k));
        return {i, c};
    }
    
    bool scatter(int k, int maxRow) {
        if (k > st_.query(i_, maxRow)) {
            return false;
        }
        for (int i = i_; i <= maxRow && k; ++i) {
            int cnt = st_.tree[st_.base + i][1];
            int c = min(cnt, k);
            cnt -= c;
            if (!cnt) {
                ++i_;
            }
            st_.update(i, vector<int64_t>(2, cnt));
            k -= c;
        }
        return true;
    }

private:
    // Template:
    // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-substring-of-one-repeating-character.cpp
    class SegmentTree {
     public:
        explicit SegmentTree(int N, int m)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2, vector<int64_t>(2)),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {

            for (int i = base; i < base + N; ++i) {
                tree[i][0] = tree[i][1] = m;
            }
            for (int i = base - 1; i >= 1; --i) {
                tree[i][0] = max(tree[i * 2][0], tree[i * 2 + 1][0]);
                tree[i][1] = tree[i * 2][1] + tree[i * 2 + 1][1];
            }
        }

        void update(int i, const vector<int64_t>& h) {
            int x = base + i;
            tree[x] = h;
            while (x > 1) {
                x /= 2;
                tree[x][0] = max(tree[x * 2][0], tree[x * 2 + 1][0]);
                tree[x][1] = tree[x * 2][1] + tree[x * 2 + 1][1];
            }
        }

        int64_t query(int L, int R) {
            L += base;
            R += base;
            int64_t result = 0;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    result += tree[L][1];
                    ++L;
                }
                if ((R & 1) == 0) {
                    result += tree[R][1];
                    --R;
                }
            }
            return result;
        }

        vector<vector<int64_t>> tree;
        int base;
    };

    SegmentTree st_;
    int m_;
    int i_;
};

// Time:  ctor:    O(n)
//        gather:  O(logn)
//        scatter: O(logn), amortized
// Space: O(n)
// design, segment tree, binary search
class BookMyShow2 {
public:
    BookMyShow2(int n, int m)
      : m_(m)
      , i_(0) {

        const auto& build = [&m] (const auto& i) {
            return vector<int64_t>({m, m});
        };
        const auto& update = [] (const auto& c) {
            return c;
        };
        const auto& query = [] (const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            if (empty(y)) {
                return x;
            }
            return vector<int64_t>({max(x[0], y[0]), x[1] + y[1]});
        };

        st_ = make_unique<SegmentTree<vector<int64_t>>>(n, build, update, query);
    }
    
    vector<int> gather(int k, int maxRow) {
        int i = 1;
        if (k > st_->tree[i][0]) {
            return {};
        }
        while (i < st_->base) {
            i = 2 * i + static_cast<int>(st_->tree[2 * i][0] < k);
        }
        if (i - st_->base > maxRow) {
            return {};
        }
        int cnt = st_->tree[i][0];
        int c = m_ - cnt;
        i -= st_->base;
        st_->update(i, vector<int64_t>(2, cnt - k));
        return {i, c};
    }
    
    bool scatter(int k, int maxRow) {
        const auto cnt = st_->query(i_, maxRow);
        if (empty(cnt) || cnt[1] < k) {
            return false;
        }
        for (int i = i_; i <= maxRow && k; ++i) {
            int cnt = st_->tree[st_->base + i][1];
            int c = min(cnt, k);
            cnt -= c;
            if (!cnt) {
                ++i_;
            }
            st_->update(i, vector<int64_t>(2, cnt));
            k -= c;
        }
        return true;
    }

private:
    // Template:
    // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-substring-of-one-repeating-character.cpp
    template <typename T>
    class SegmentTree {
     public:
        explicit SegmentTree(
            int N,
            const function<T(const int&)>& build_fn,
            const function<T(const T&)>& update_fn,
            const function<T(const T&, const T&)>& query_fn)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            build_fn_(build_fn),
            query_fn_(query_fn),
            update_fn_(update_fn) {

            for (int i = base; i < base + N; ++i) {
                tree[i] = build_fn_(i - base);
            }
            for (int i = base - 1; i >= 1; --i) {
                tree[i] = query_fn_(tree[2 * i], tree[2 * i + 1]);
            }
        }

        void update(int i, const T& h) {
            int x = base + i;
            tree[x] = update_fn_(h);
            while (x > 1) {
                x /= 2;
                tree[x] = query_fn_(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        T query(int L, int R) {
            L += base;
            R += base;
            T left, right;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    left = query_fn_(left, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    right = query_fn_(tree[R], right);
                    --R;
                }
            }
            return query_fn_(left, right);
        }

        vector<T> tree;
        int base;

    private:
        const function<T(const int&)> build_fn_;
        const function<T(const T&)> update_fn_;
        const function<T(const T&, const T&)> query_fn_;
    };

    unique_ptr<SegmentTree<vector<int64_t>>> st_;
    int m_;
    int i_;
};
