// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (const auto& c : s) {
            number *= 26;
            number += c  - 'A' + 1;
        }
        return number;
    }
};
