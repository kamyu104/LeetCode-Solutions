// Time:  O(nlogr), r = max(nums)
// Space: O(logr)

// number theory, dp, prefix sum
class Solution {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        int64_t result = 0;
        vector<tuple<int, int, int64_t>> dp;
        for (int64_t right = 0, prefix = 0; right < size(nums); ++right) {
            dp.emplace_back(right, nums[right], prefix);
            prefix += nums[right];
            vector<tuple<int, int, int64_t>> new_dp;
            new_dp.reserve(size(dp));
            for (const auto& [left, g, p] : dp) {  // Time: O(logr)
                const int ng = gcd(g, nums[right]);  // Total Time: O(nlogr)
                if (empty(new_dp) || get<1>(new_dp.back()) != ng) {
                    new_dp.emplace_back(left, ng, p);  // left and ng are both strictly increasing
                }
            }
            dp = move(new_dp);
            for (const auto& [left, g, p] : dp) {
                if (right - left + 1 < k) {
                    break;
                }
                result = max(result, (prefix - p) * g);
            }
        }
        return result;
    }
};

// Time:  O(nlogr), r = max(nums)
// Space: O(n)
// number theory, dp, prefix sum
class Solution2 {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int64_t result = 0;
        vector<pair<int, int>> dp;
        for (int right = 0; right < size(nums); ++right) {
            dp.emplace_back(right, nums[right]);
            vector<pair<int, int>> new_dp;
            new_dp.reserve(size(dp));
            for (const auto& [left, g] : dp) {  // Time: O(logr)
                const int ng = gcd(g, nums[right]);  // Total Time: O(nlogr)
                if (empty(new_dp) || new_dp.back().second != ng) {
                    new_dp.emplace_back(left, ng);  // left and ng are both strictly increasing
                }
            }
            dp = move(new_dp);
            for (const auto& [left, g] : dp) {
                if (right - left + 1 < k) {
                    break;
                }
                result = max(result, (prefix[right + 1] - prefix[left]) * g);
            }
        }
        return result;
    }
};

// Time:  O(n * logr * (logn * logr)) = O(n * (logr)^2 * logn), r = max(nums)
// Space: O(nlogn)
// number theory, binary search, rmq, sparse table, prefix sum
class Solution3 {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        const auto& binary_search_right = [&](int left, int right, const auto& check) {
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
    
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int64_t result = 0;
        SparseTable rmq(nums, gcd<int, int>);
        for (int left = 0; left < size(nums); ++left) {
            for (int right = left; right < size(nums); ++right) {  // O(logr) times
                const int g = rmq.query(left, right);
                right = binary_search_right(right, size(nums) - 1, [&](const auto& x) {
                    return rmq.query(left, x) >= g;
                });  // Time: O(logn) * O(logr)
                if (right - left + 1 >= k) {
                    result = max(result, (prefix[right + 1] - prefix[left]) * g);
                }
            }
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(n * logn * logr), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            st.assign(k + 1, vector<int64_t>(n));
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int64_t query(int L, int R) const {
            const int i = __lg(R - L + 1);
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(logr)
        }
    
    private:
        vector<vector<int64_t>> st;
        const function<int (int, int)>& fn;
    };
};
