// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        for (const auto& x : s) {
            total += x - 'a' + 1;
        }
        int prefix = 0;
        for (const auto& x : s) {
            prefix += x - 'a' + 1;
            if (prefix == total - prefix) {
                return true;
            }
        }
        return false;
    }
};
