// Time:  O(26 * n)
// Space: O(26)

// greedy
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }
        string result;
        int top1 = 25;
        for (;;) {
            for (; top1 >= 0; --top1) {
                if (cnt[top1]) {
                    break;
                }
            }
            if (top1 == -1) {
                break;
            }
            const int c = min(cnt[top1], repeatLimit - static_cast<int>(!empty(result) && result.back() == 'a' + top1));
            cnt[top1] -= c;
            result.append(c, 'a' + top1);
            int top2 = top1 - 1;
            for (; top2 >= 0; --top2) {
                if (cnt[top2]) {
                    break;
                }
            }
            if (top2 == -1) {
                break;
            }
            --cnt[top2];
            result.push_back('a' + top2);
        }
        return result;
    }
};
