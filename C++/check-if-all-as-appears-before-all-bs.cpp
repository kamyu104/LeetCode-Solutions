// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
