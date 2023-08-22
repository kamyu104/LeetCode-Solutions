// Time:  O(n)
// Space: O(1)

// greedy, two pointers
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        for (const auto& c : str1) {
            if (((str2[i] - c) % 26 + 26) % 26 > 1) {
                continue;
            }
            if (++i == size(str2)) {
                return true;
            }
        }
        return false;
    }
};
