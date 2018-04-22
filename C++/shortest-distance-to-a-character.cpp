// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result(S.length(), S.length());
        int prev = -S.length();
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == C) {
                prev = i;
            }
            result[i] = min(result[i], abs(i - prev));
        }
        for (int i = S.length() - 1; i >= 0; --i) {
            if (S[i] == C) {
                prev = i;
            }
            result[i] = min(result[i], abs(i - prev));
        }
        return result;
    }
};
