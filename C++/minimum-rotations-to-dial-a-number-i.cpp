// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int minRotations(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            const auto& diff = abs(s[i] - (i - 1 >= 0 ? s[i - 1] : '0'));
            result += min(diff, 10 - diff);
        }
        return result;
    }
};
