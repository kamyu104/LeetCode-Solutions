// Time:  O(n)
// Space: O(1)

// Greedy solution.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        int i = 0;
        for (const auto& c : t) {
            if (c == s[i]) { 
                ++i;
            }
            if (i == s.length()) {
                return true;
            }
        }
        return false;
    }
};
