// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * count(cbegin(s), cend(s), letter) / size(s);
    }
};
