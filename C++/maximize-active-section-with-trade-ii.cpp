// Time:  O(nlogn + q)
// Space: O(nlogn)

// sparse table
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(const string& s, vector<vector<int>>& queries) {
        int cnt1 = 0;
        vector<pair<int, int>> idxs;
        vector<int> lookup(size(s));
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '0') {
                if (i - 1 >= 0 && s[i - 1] == '0') {
                    ++idxs.back().second;
                } else {
                    idxs.emplace_back(i, 1);
                }
            } else {
                ++cnt1;
            }
            lookup[i] = size(idxs) - 1;
        }
        if (empty(idxs)) {
            return vector<int>(size(queries), cnt1);
        }        
        vector<int> arr(idxs.size() - 1);
        for (int i = 0; i + 1 < idxs.size();  ++i) {
            arr[i] = idxs[i].second + idxs[i + 1].second;
        }
        SparseTable st(arr, [](int a, int b) { return max(a, b); });
        vector<int> result(size(queries), cnt1);
        for (int i = 0; i < size(queries); ++i) {
            const int l = queries[i][0], r = queries[i][1];
            const int left = lookup[l] + 1, right = lookup[r] - (s[r] == '0' ? 1 : 0);
            const int left_cnt = lookup[l] != -1 ? idxs[lookup[l]].second - (l - idxs[lookup[l]].first) : -1;
            const int right_cnt = lookup[r] != -1 ? r - idxs[lookup[r]].first + 1 : -1;
            if (left <= right - 1) {
                result[i] = max(result[i], cnt1 + st.query(left, right - 1));
            }
            if (s[l] == '0' && s[r] == '0' && lookup[l] + 1 == lookup[r]) {
                result[i] = max(result[i], cnt1 + left_cnt + right_cnt);
            }
            if (s[l] == '0' && lookup[l] + 1 <= right) {
                result[i] = max(result[i], cnt1 + left_cnt + idxs[lookup[l] + 1].second);
            }
            if (s[r] == '0' && left <= lookup[r] - 1) {
                result[i] = max(result[i], cnt1 + right_cnt + idxs[lookup[r] - 1].second);
            }
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn * 1), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            bit_length.assign(1, 0);
            for (int i = 0; i <= k; ++i) {
                const int cnt = min(1 << i, (n + 1) - static_cast<int>(size(bit_length)));
                for (int _ = 0; _ < cnt; ++_) {
                    bit_length.emplace_back(i + 1);
                }
            }
            st.assign(k + 1, vector<int>(n));
            if (empty(st)) {
                return;
            }
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int query(int L, int R) const {
            const int i = bit_length[R - L + 1] - 1;
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(1)
        }

    private:
        vector<vector<int>> st;
        const function<int (int, int)>& fn;
        vector<int> bit_length;
    };
};
