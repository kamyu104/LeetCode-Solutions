// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        for (auto it = S.rbegin(); it < S.rend(); ++it) {
            if (*it == '-') {
                continue;
            }
            if (result.length() % (K + 1) == K) {
                result += '-';
            }
            result += toupper(*it);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
