// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkZeroOnes(string s) {
        vector<int> max_cnt(2);
        for (int i = 0, cnt = 0; i <= size(s); ++i, ++cnt) {
            if (i == size(s) || (i >= 1 && s[i] != s[i - 1])) {
                max_cnt[s[i - 1] - '0'] = max(max_cnt[s[i - 1] - '0'], cnt);
                cnt = 0;
            }
        }
        return max_cnt[0] < max_cnt[1];
    }
};
