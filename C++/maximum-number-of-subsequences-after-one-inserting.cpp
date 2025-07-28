// Time:  O(n)
// Space: O(1)

// prefix sum, dp
class Solution {
public:
    long long numOfSubsequences(string s) {
        int64_t cnt_l = 0, cnt_c = 0;
        int64_t cnt_t = count(cbegin(s), cend(s), 'T');
        int64_t mx_cnt_lt = 0, cnt_lct = 0, cnt_lc = 0, cnt_ct = 0;
        for (const auto& x : s) {
            mx_cnt_lt = max(mx_cnt_lt, cnt_l * cnt_t);
            if (x == 'L') {
                ++cnt_l;
            } else if (x == 'C') {
                ++cnt_c;
                cnt_lc += cnt_l;
            } else if (x == 'T') {
                --cnt_t;
                cnt_ct += cnt_c;
                cnt_lct += cnt_lc;
            }
        }
        mx_cnt_lt = max(mx_cnt_lt, cnt_l * cnt_t);
        return cnt_lct + max({cnt_ct, mx_cnt_lt, cnt_lc});
    }
};
