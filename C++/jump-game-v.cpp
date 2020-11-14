// Time:  O(n)
// Space: O(n)

// sliding window + top-down dp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<vector<int>> left(arr.size());
        deque<int> decreasing_dq;
        for (int i = 0; i < arr.size(); ++i) {
            if (!decreasing_dq.empty() && i - decreasing_dq.front() == d + 1) {
                decreasing_dq.pop_front();
            }
            while (!decreasing_dq.empty() && arr[decreasing_dq.back()] < arr[i]) {
                if (!left[i].empty() && arr[left[i].back()] != arr[decreasing_dq.back()]) {
                    left[i].clear();
                }
                left[i].emplace_back(decreasing_dq.back());
                decreasing_dq.pop_back();
            }
            decreasing_dq.emplace_back(i);
        }
        vector<vector<int>> right(arr.size());
        decreasing_dq.clear();
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (!decreasing_dq.empty() && decreasing_dq.front() - i == d + 1) {
                decreasing_dq.pop_front();
            }
            while (!decreasing_dq.empty() && arr[decreasing_dq.back()] < arr[i]) {
                if (!right[i].empty() && arr[right[i].back()] != arr[decreasing_dq.back()]) {
                    right[i].clear();
                }
                right[i].emplace_back(decreasing_dq.back());
                decreasing_dq.pop_back();
            }
            decreasing_dq.emplace_back(i);
        }

        int result = 0;
        vector<int> lookup(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result = max(result, dp(arr, d, i, left, right, &lookup));
        }
        return result;
    }

private:
    int dp(const vector<int>& arr, int d, int i,
           const vector<vector<int>>& left, const vector<vector<int>>& right,
           vector<int> *lookup) {
        if ((*lookup)[i]) {
            return (*lookup)[i];
        }
        (*lookup)[i] = 1;
        // each dp[j] will be visited at most twice 
        for (const auto& j : left[i]) {
            (*lookup)[i] = max((*lookup)[i], dp(arr, d, j, left, right, lookup) + 1);
        }
        for (const auto& j : right[i]) {
            (*lookup)[i] = max((*lookup)[i], dp(arr, d, j, left, right, lookup) + 1);
        }
        return (*lookup)[i];
    }
};

// Time:  O(nlogn)
// Space: O(n)
// mono stack + bottom-up dp
class Solution2 {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<vector<int>> left(arr.size());
        vector<int> decreasing_stk;
        for (int i = 0; i < arr.size(); ++i) {
            while (!decreasing_stk.empty() && arr[decreasing_stk.back()] < arr[i]) {
                if (i - decreasing_stk.back() <= d) {
                    if (!left[i].empty() && arr[left[i].back()] != arr[decreasing_stk.back()]) {
                        left[i].clear();
                    }
                    left[i].emplace_back(decreasing_stk.back());
                }
                decreasing_stk.pop_back();
            }
            decreasing_stk.emplace_back(i);
        }
        vector<vector<int>> right(arr.size());
        decreasing_stk.clear();
        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!decreasing_stk.empty() && arr[decreasing_stk.back()] < arr[i]) {
                if (decreasing_stk.back() - i <= d) {
                    if (!right[i].empty() && arr[right[i].back()] != arr[decreasing_stk.back()]) {
                        right[i].clear();
                    }
                    right[i].emplace_back(decreasing_stk.back());
                }
                decreasing_stk.pop_back();
            }
            decreasing_stk.emplace_back(i);
        }
        
        vector<pair<int, int>> sorted_arr;
        for (int i = 0; i < arr.size(); ++i) {
            sorted_arr.emplace_back(arr[i], i);
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        vector<int> dp(arr.size(), 1);
        for (const auto& [_, i] : sorted_arr) {
            dp[i] = 1;
            // each dp[j] will be visited at most twice 
            for (const auto& j : left[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            for (const auto& j : right[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};

// Time:  O(nlogn)
// Space: O(n)
// mono stack + bottom-up dp + segment tree
class Solution3 {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> left(arr.size()), decreasing_stk;
        iota(left.begin(), left.end(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            while (!decreasing_stk.empty() && arr[decreasing_stk.back()] < arr[i]) {
                if (i - decreasing_stk.back() <= d) {
                    left[i] = decreasing_stk.back();
                }
                decreasing_stk.pop_back();
            }
            decreasing_stk.emplace_back(i);
        }
        vector<int> right(arr.size());
        decreasing_stk.clear();
        iota(right.begin(), right.end(), 0);
        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!decreasing_stk.empty() && arr[decreasing_stk.back()] < arr[i]) {
                if (decreasing_stk.back() - i <= d) {
                    right[i] = decreasing_stk.back();
                }
                decreasing_stk.pop_back();
            }
            decreasing_stk.emplace_back(i);
        }

        vector<pair<int, int>> sorted_arr;
        for (int i = 0; i < arr.size(); ++i) {
            sorted_arr.emplace_back(arr[i], i);
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        SegmentTree segment_tree(arr.size());
        for (const auto& [_, i] : sorted_arr) {
            segment_tree.update(i, i, segment_tree.query(left[i], right[i]) + 1);
        }
        return segment_tree.query(0, arr.size() - 1);
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
            auto result = 0;
            if (L > R) {
                return result;
            }
            L += N_; R += N_;
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
            tree_[x] = val;
            if (x < N_) {
                lazy_[x] = val;
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                if (lazy_[x] != 0) {
                    tree_[x] = lazy_[x];
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
};
