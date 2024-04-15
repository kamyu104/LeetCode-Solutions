// Time:  O(n * m * logr), r = max(nums)
// Space: O(n + logr)

// dp, mono deque, two pointers
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        static const int INF = numeric_limits<int>::max();

        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int L = bit_length(ranges::max(nums));
        const auto& update = [&](auto& cnt, int x, int d) {
            for (int i = 0; i < L; ++i) {
                if (x & (1 << i)) {
                    cnt[i] += d;
                }
            }
        };

        const auto& mask = [&](const auto& cnt, int l) {
            int result = 0;
            for (int i = 0; i < L; ++i) {
                if (cnt[i] == l) {
                    result |= 1 << i;
                }
            }
            return result;
        };

        vector<int> dp(size(nums) + 1, INF);
        dp[0] = 0;
        for (int j = 0; j < size(andValues); ++j) {
            vector<int> new_dp(size(dp), INF), cnt(L), l(size(dp));
            deque<int> dq;
            for (int right = j, left = right, idx = right; right < size(nums); ++right) {
                update(cnt, nums[right], +1);
                if (mask(cnt, right - left + 1) <= andValues[j]) {
                    for (; left <= right && mask(cnt, right - left + 1) <= andValues[j]; ++left) {
                        update(cnt, nums[left], -1);
                    }
                    --left;
                    update(cnt, nums[left], +1);  // try to move to the last left s.t. mask(cnt, right - left + 1) == andValues[j]
                }
                if ((andValues[j] & nums[right]) == andValues[j]) {
                    l[right + 1] = l[right] + 1;
                }
                if (mask(cnt, right - left + 1) != andValues[j]) {
                    continue;
                }
                // new_dp[right+1] = min(dp[left-l[left]], dp[left-l[left]+1], ..., dp[left])+nums[right]
                for (; idx <= left; ++idx) {
                    for (; !empty(dq) && dp[dq.back()] >= dp[idx]; dq.pop_back());
                    dq.emplace_back(idx);
                }
                for (; !empty(dq) && dq.front() < left - l[left]; dq.pop_front());
                if (!empty(dq)) {
                    if (dp[dq.front()] != INF) {
                        new_dp[right + 1] = dp[dq.front()] + nums[right];
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};

// Time:  O(m * n * (logn + logr)), r = max(nums)
// Space: O(n + logr)
// dp, sparse table
class Solution2 {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(nums) + 1, INF);
        dp[0] = 0;
        for (int j = 0; j < size(andValues); ++j) {
            vector<int> new_dp(size(nums) + 1, INF);
            vector<pair<int, int>> masks;
            SparseTable st(dp, [&](int i, int j) { return min(i, j); });
            for (int i = j; i < size(nums); ++i) {
                masks.emplace_back(nums[i], i);
                for (auto& [mask, _] : masks) {
                    mask &= nums[i];
                }
                masks.erase(unique(begin(masks), end(masks), [](const auto& a, const auto& b) {
                    return a.first == b.first;
                }), end(masks));
                for (int k = 0; k < size(masks); ++k) {
                    const auto [mask, left] = masks[k];
                    if (mask == andValues[j]) {
                        const int right = k + 1 != size(masks) ? masks[k + 1].second - 1 : i;
                        if (st.query(left, right) != INF) {
                            // any j in range(left, right+1) has same and(nums[j:i+1]) = mask
                            new_dp[i + 1] = min(new_dp[i + 1], st.query(left, right) + nums[i]);
                        }
                        break;
                    }
                }
            }
            dp = move(new_dp);
      }
      return dp.back() == INF ? -1 : dp.back();
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            st.assign(k + 1, vector<int>(n));
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int query(int L, int R) const {
            const int i = __lg(R - L + 1);
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(1)
        }
    
    private:
        vector<vector<int>> st;
        const function<int (int, int)>& fn;
    };
};

// Time:  O(n * m * logr), r = max(nums)
// Space: O(n * m * logr)
// memoization
class Solution3 {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        static const int INF = numeric_limits<int>::max();

        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int FULL_MASK = (1 << bit_length(ranges::max(nums))) - 1;
        vector<vector<unordered_map<int, int>>> lookup(size(nums), vector<unordered_map<int, int>>(size(andValues)));
        const function<int (int, int, int)> memoization = [&](int i, int j, int mask) {
            if (i == size(nums) && j == size(andValues)) {
                return 0;
            }
            if (i == size(nums) || j == size(andValues) || mask < andValues[j]) {
                return INF;
            }
            if (!lookup[i][j].count(mask)) {
                int curr = memoization(i + 1, j, mask & nums[i]);
                if ((mask & nums[i]) == andValues[j]) {
                    const int total = memoization(i + 1, j + 1, FULL_MASK);
                    if (total != INF) {
                        curr = min(curr, nums[i] + total);
                    }
                }
                lookup[i][j][mask] = curr;
            }
            return lookup[i][j][mask];
        };

        const int result = memoization(0, 0, FULL_MASK);
        return result != INF ? result : -1;
    }
};
