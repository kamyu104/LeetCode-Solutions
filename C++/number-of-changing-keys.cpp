// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int countKeyChanges(string s) {
        int result = 0;
        for (int i = 0; i + 1 < size(s); ++i) {
            result += tolower(s[i]) != tolower(s[i + 1]) ? 1 : 0;
        }
        return result;
    }
};
