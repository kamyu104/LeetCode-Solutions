// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        uint64_t n = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (isdigit(S[i])) {
                n *= S[i] - '0';
            } else {
                ++n;
            }
        }

        for (int i = S.length() - 1; i >= 0; --i) {
            K %= n;
            if (K == 0 && isalpha(S[i])) {
                return (string) "" + S[i];
            }

            if (isdigit(S[i])) {
                n /= S[i] - '0';
            } else {
                --n;
            }
        }
    }
};
