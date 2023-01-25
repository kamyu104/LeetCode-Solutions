// Time:  O(n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (s.find('1') != string::npos) == (target.find('1') != string::npos);
    }
};
