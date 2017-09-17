// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;  //  keep lower bound and upper bound of '(' counts
        for (const auto& c : s) {
            if (c == '(') {
                ++lower;
                ++upper;
            } else if (c == ')') {
                if (upper == 0) {  // '(' count is not enough
                    return false;
                }
                lower = max(lower - 1, 0);
                --upper;
            } else {
                lower = max(lower - 1, 0);
                ++upper;
            }
        }
        return lower == 0;  // range of '(' count is valid
    }
};
