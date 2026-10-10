// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int minRotations(string s) {
        const auto& f = [](char a, char b) {
            const auto& diff = abs(a - b);
            return min(diff, 10 - diff);
        };

        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            result += f(s[i], i - 1 >= 0 ? s[i - 1] : '0');
        }
        return result;
    }
};
