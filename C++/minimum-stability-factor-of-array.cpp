// Time:  O(nlogn * logr)
// Space: O(nlogn)

// number theory, binary search, rmq, sparse table, greedy
class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
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

        SparseTable rmq(nums, gcd<int, int>);
        const auto& check = [&](int l) {
            int cnt = 0;
            for (int i = 0; i + l - 1 < size(nums);) {
                if (rmq.query(i, i + l - 1) >= 2) {
                    ++cnt;
                    i += l;
                } else {
                    ++i;
                }
            }
            return cnt > maxC;
        };

        return binary_search_right(1, size(nums), check);
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn * logr), Space: O(nlogn)
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
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(logr)
        }
    
    private:
        vector<vector<int64_t>> st;
        const function<int (int, int)>& fn;
    };
};
