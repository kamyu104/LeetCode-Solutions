// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    int minLength(string s) {
        string stk;
        for (const auto& c : s) {
            if (!empty(stk) && ((stk.back() == 'A' && c == 'B') || (stk.back() == 'C' && c == 'D'))) {
                stk.pop_back();
                continue;
            }
            stk.push_back(c);
        }
        return size(stk);
    }
};
