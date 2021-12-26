// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canBeValid(string s, string locked) {
        auto check = [&s, &locked](char c) {
            const int begin = (c == '(') ? 0 : size(s) - 1;
            const int end = (c == '(') ? size(s) : -1;
            const int d = (c == '(') ? 1 : -1;
            for (int i = begin, cnt = 0, bal = 0; i != end; i += d) {
                if (locked[i] == '0') {
                    ++cnt;
                } else {
                    bal += (s[i] == c) ? 1 : -1;
                    if (cnt + bal < 0) {
                        return false;
                    }
                }
            }
            return true;
        };

        return size(s) % 2 == 0 && check('(') && check(')');
    }
};
