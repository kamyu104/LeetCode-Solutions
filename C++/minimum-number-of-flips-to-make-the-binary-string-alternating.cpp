// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minFlips(string s) {
        int result = numeric_limits<int>::max();
        int cnt1 = 0, cnt2 = 0;
        int l = (size(s) % 2) ? 2 * size(s) - 1 : size(s);
        for (int i = 0; i < l; ++i) {
            if (i >= size(s)) {
                cnt1 -= (s[i % size(s)] - '0') ^ ((i - size(s)) % 2) ^ 0;
                cnt2 -= (s[i % size(s)] - '0') ^ ((i - size(s)) % 2) ^ 1;
            }
            cnt1 += (s[i % size(s)] - '0') ^ (i % 2) ^ 0;
            cnt2 += (s[i % size(s)] - '0') ^ (i % 2) ^ 1;
            if (i >= size(s) - 1) {
                result = min({result, cnt1, cnt2});
            }
        }
        return result;
    }
};
