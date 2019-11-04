// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string removeOuterParentheses(string S) {
        static const int deep = 1;
        string result;
        int cnt = 0;
        for (const auto& c : S) {
            if (c == '(' && cnt++ >= deep) {
                result += c;
            }
            if (c == ')' && cnt-- > deep) {
                result += c;
            }
        }
        return result;
    }
};
