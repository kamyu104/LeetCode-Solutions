// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        return abs(count(cbegin(s), cend(s), 'a') - count(cbegin(s), cend(s), 'b'));
    }
};
