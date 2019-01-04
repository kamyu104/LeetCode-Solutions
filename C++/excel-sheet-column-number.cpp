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

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int titleToNumber(string s) {
        return accumulate(s.cbegin(), s.cend(), 0,
                          [](int sum, char c) { 
                              return sum * 26 + c - 'A' + 1; 
                          });
    }
};
