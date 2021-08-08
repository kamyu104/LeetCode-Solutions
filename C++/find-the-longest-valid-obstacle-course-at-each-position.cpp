// Time:  O(nlogn)
// Space: O(n)

// binary search solution
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> result, stk;
        for (const auto& x : obstacles) {
            const auto& i = distance(cbegin(stk), upper_bound(cbegin(stk), cend(stk), x));
            result.emplace_back(i + 1);
            if (i == size(stk)) {
                stk.emplace_back();
            }
            stk[i] = x;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// segment tree solution
class Solution2 {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        set<int> sorted_obstacles(cbegin(obstacles), cend(obstacles));
        unordered_map<int, int> lookup;
        for (const auto& x : sorted_obstacles) {
            lookup[x] = size(lookup);
        }
        SegmentTree segment_tree(size(lookup));
        vector<int> result;
        for (const auto& x : obstacles) {
            const auto& cnt = segment_tree.query(0, lookup[x]) + 1;
            result.emplace_back(cnt);
            segment_tree.update(lookup[x], lookup[x], cnt);
        }
        return result;
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
            tree_[x] = max(tree_[x], val);
            if (x < N_) {
                lazy_[x] = max(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                tree_[x] = max(tree_[x], lazy_[x]);
            }
        }

        void push(int x) {
            for (int h = H_; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y] > 0) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }
    };
};
