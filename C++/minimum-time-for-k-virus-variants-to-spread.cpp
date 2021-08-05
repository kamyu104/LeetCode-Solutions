// Time:  O(nlogn * logr), r is the sum of range x size and range y size
// Space: O(n)

// competitive programming solution
class Solution {
public:
    int minDayskVariants(vector<vector<int>>& points, int k) {
        std::transform(begin(points), end(points), begin(points),
                       [](const auto& v) {
                           return vector<int>({v[0] + v[1], v[0] - v[1]});  // rotate
                       });
        const auto& compare_y = [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; };
        const int min_x = (*min_element(cbegin(points), cend(points)))[0];
        const int max_x = (*max_element(cbegin(points), cend(points)))[0];
        const int min_y = (*min_element(cbegin(points), cend(points), compare_y))[1];
        const int max_y = (*max_element(cbegin(points), cend(points), compare_y))[1];
        int64_t left = 0, right = ((int64_t(max_x) - min_x) + (int64_t(max_y) - min_y) + 1) / 2;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(points, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;                       
    }

private:
    class SegmentTree {
    public:
        SegmentTree(int N)
            : N_(N),
              tree_(2 * N),
              lazy_(N)
        {
            H_ = 1;
            while ((1 << H_) < N) {
                ++H_;
            }
        }

        void update(int L, int R, int h) {
            L += N_; R += N_;
            int L0 = L, R0 = R;
            while (L <= R) {
                if ((L & 1) == 1) {
                    apply(L++, h);
                }
                if ((R & 1) == 0) {
                    apply(R--, h);
                }
                L >>= 1; R >>= 1;
            }
            pull(L0); pull(R0);
        }

        int query(int L, int R) {
            L += N_; R += N_;
            auto result = 0;
            push(L); push(R);
            while (L <= R) {
                if ((L & 1) == 1) {
                    result = max(result, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    result = max(result, tree_[R--]);
                }
                L >>= 1; R >>= 1;
            }
            return result;
        }

    private:
        int N_, H_;
        vector<int> tree_, lazy_;

        void apply(int x, int val) {
            tree_[x] += val;
            if (x < N_) {
                lazy_[x] += val;
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                if (lazy_[x]) {
                    tree_[x] += lazy_[x];
                }
            }
        }

        void push(int x) {
            for (int h = H_; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y] != 0) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }
    };

    bool check(const vector<vector<int>>& points, int k, int l) {  // Time: O(nlogn), Space: O(n)
        using Event = tuple<int64_t, int64_t, int64_t, int64_t>;
        vector<Event> intervals;
        unordered_set<int64_t> y_set;
        for (const auto& p : points) {
            // add [y0, y1] by 1 in [x0, x1+1)
            int64_t x0 = int64_t(p[0]) - l, y0 = int64_t(p[1]) - l, x1 = int64_t(p[0]) + l, y1 = int64_t(p[1]) + l;
            intervals.emplace_back(x0    , +1, y0, y1);
            intervals.emplace_back(x1 + 1, -1, y0, y1);
            y_set.emplace(y0);
            y_set.emplace(y1);
        }
        sort(begin(intervals), end(intervals));
        vector<int64_t> sorted_y(cbegin(y_set), cend(y_set));
        sort(begin(sorted_y), end(sorted_y));
        unordered_map<int64_t, int> y_to_idx;
        for (int i = 0; i < size(sorted_y); ++i) {  // coordinate compression
            y_to_idx[sorted_y[i]] = i;
        }
        SegmentTree st(size(y_to_idx));
        for (const auto& [_, v, y0, y1] : intervals) {  // line sweep
            st.update(y_to_idx[y0], y_to_idx[y1], v);
            if (st.query(0, size(y_to_idx) - 1) >= k) {
                return true;
            }
        }
        return false;
    }
};

// Time:  O(n^2 * logr), r is the sum of range x size and range y size
// Space: O(n)
// interview solution
class Solution2 {
public:
    int minDayskVariants(vector<vector<int>>& points, int k) {
        std::transform(begin(points), end(points), begin(points),
                       [](const auto& v) {
                           return vector<int>({v[0] + v[1], v[0] - v[1]});  // rotate
                       });
        const auto& compare_y = [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; };
        const int min_x = (*min_element(cbegin(points), cend(points)))[0];
        const int max_x = (*max_element(cbegin(points), cend(points)))[0];
        const int min_y = (*min_element(cbegin(points), cend(points), compare_y))[1];
        const int max_y = (*max_element(cbegin(points), cend(points), compare_y))[1];
        int64_t left = 0, right = ((int64_t(max_x) - min_x) + (int64_t(max_y) - min_y) + 1) / 2;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(points, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;                       
    }

private:
    bool check(const vector<vector<int>>& points, int k, int l) {  // Time: O(n^2), Space: O(n)
        unordered_map<int64_t, unordered_map<int64_t, int>> intervals;
        unordered_set<int64_t> y_set;
        for (const auto& p : points) {
            // add [y0, y1+1) by 1 in [x0, x1+1)
            int64_t x0 = int64_t(p[0]) - l, y0 = int64_t(p[1]) - l, x1 = int64_t(p[0]) + l, y1 = int64_t(p[1]) + l;
            ++intervals[x0][y0];
            --intervals[x0][y1 + 1];
            --intervals[x1 + 1][y0];
            ++intervals[x1 + 1][y1 + 1];
            y_set.emplace(y0);
            y_set.emplace(y1 + 1);
        }
        vector<int64_t> sorted_x;
        for (const auto& [x, _] : intervals) {
            sorted_x.emplace_back(x);
        }
        sort(begin(sorted_x), end(sorted_x));
        vector<int64_t> sorted_y(cbegin(y_set), cend(y_set));
        sort(begin(sorted_y), end(sorted_y));
        unordered_map<int64_t, int> count;
        for (const auto& x : sorted_x) {  // line sweep
            for (const auto& [y, c] : intervals[x]) {
                count[y] += c;
            }
            int cnt = 0;
            for (const auto& y : sorted_y) {
                cnt += count[y];
                if (cnt >= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
