// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk = {""};
        for (const auto& c : s) {
            if (c == '(') {
                stk.emplace_back();
            } else if (c == ')') {
                auto end = move(stk.back()); stk.pop_back();
                reverse(end.begin(), end.end());
                stk.back() += end;
            } else {
                stk.back().push_back(c);
            }
        }
        return stk[0];
    }
};
