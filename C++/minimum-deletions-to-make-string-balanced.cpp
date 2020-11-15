// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minimumDeletions(string s) {
        int result = 0, b_cnt = 0;
        for (const auto& c : s) {
            if (c == 'b') {
                ++b_cnt;
            } else if (b_cnt) {
                --b_cnt;
                ++result;
            }
        }
        return result;
    }
};
