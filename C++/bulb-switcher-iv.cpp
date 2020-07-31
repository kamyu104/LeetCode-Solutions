// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minFlips(string target) {
        int result = 0;
        char curr = '0';
        for (const auto& c : target) {
            if (c == curr) {
                continue;
            }
            curr = c;
            ++result;
        }
        return result;
    }
};
