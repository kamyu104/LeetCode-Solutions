// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;  //  keep lower bound and upper bound of '(' counts
        for (const auto& c : s) {
            lower += (c == '(') ? 1 : -1;
            upper -= (c == ')') ? 1 : -1;
            if (upper < 0) break;
            lower = max(lower, 0);
        }
        return lower == 0;  // range of '(' count is valid
    }
};
