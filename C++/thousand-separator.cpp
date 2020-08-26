// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string thousandSeparator(int n) {
        string result;
        const auto& s = to_string(n);
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && (s.length() - i) % 3 == 0) {
                result += ".";
            }
            result += s[i];
        }
        return result;
    }
};
