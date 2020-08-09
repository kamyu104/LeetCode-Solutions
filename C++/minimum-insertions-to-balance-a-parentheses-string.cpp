// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minInsertions(string s) {
        int add = 0, bal = 0;
        for (const auto& c: s) {
            if (c == '(') {
                if (bal % 2 > 0) {
                    ++add;  // add ')' to make sure consecutive ')'
                    --bal;
                }
                bal += 2;
            } else {
                --bal;
                if (bal < 0) {
                    ++add;  // add '('
                    bal += 2;
                }
            }
        }
        return add + bal;
    }
};
