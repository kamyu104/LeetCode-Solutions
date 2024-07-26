// Time:  O(nlogn)
// Space: O(n)

// Binary search solution with STL.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        // Find the first index "left" which satisfies LIS[left] >= target
        auto it = lower_bound(LIS->begin(), LIS->end(), target);

        // If not found, append the target.
        if (it == LIS->end()) {
            LIS->emplace_back(target);
        } else {
            *it = target;
        }
    }
};

// Binary search solution.
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        int left = 0, right = LIS->size() - 1;
        auto comp = [](int x, int target) { return x >= target; };

        // Find the first index "left" which satisfies LIS[left] >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comp((*LIS)[mid], target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If not found, append the target.
        if (left == LIS->size()) {
            LIS->emplace_back(target);
        } else {
            (*LIS)[left] = target;
        }
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bit, fenwick tree
class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> sorted_nums(cbegin(nums), cend(nums));
        unordered_map<int, int> val_to_idx;
        for (const auto& num : sorted_nums) {
            val_to_idx[num] = size(val_to_idx);
        }
        const auto& fn = [](const auto& a, const auto& b) {
            return max(a, b);
        };

        BIT<int> bit(size(val_to_idx), 0, fn);
        for (const auto& x : nums) {
            bit.update(val_to_idx[x], bit.query(val_to_idx[x] - 1) + 1);
        }
        return bit.query(size(val_to_idx) - 1);
    }

private:
    template<typename T>
    class BIT {
    public:
        BIT(int n, T val, const function<T (T, T)> fn)
          : bit_(n + 1, val),
            fn_(fn) {  // 0-indexed
        }
        
        void update(int i, T val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] = fn_(bit_[i], val);
            }
        }

        T query(int i) const {
            ++i;
            auto total = bit_[0];
            for (; i > 0; i -= lower_bit(i)) {
                total = fn_(total, bit_[i]);
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<T> bit_;
        const function<T (T, T)> fn_;
    };
};

// Time:  O(nlogn)
// Space: O(n)
// optimized from Solution5
class Solution4 {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> sorted_nums(cbegin(nums), cend(nums));
        unordered_map<int, int> val_to_idx;
        for (const auto& x : sorted_nums) {
            val_to_idx[x] = size(val_to_idx);
        }
        SegmentTree st(size(val_to_idx));
        for (const auto& x : nums) {
            st.update(val_to_idx[x], val_to_idx[x],
                      (val_to_idx[x] >= 1) ? st.query(0, val_to_idx[x] - 1) + 1 : 1);
        }
        return (size(val_to_idx) >= 1) ? st.query(0, size(val_to_idx) - 1) : 0;
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

// Time:  O(n^2)
// Space: O(n)
// Traditional DP solution.
class Solution5 {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);  // dp[i]: the length of LIS ends with nums[i]
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
