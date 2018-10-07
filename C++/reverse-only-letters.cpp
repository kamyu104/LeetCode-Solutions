// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string result;
        int i = S.length() - 1;
        for (const auto& c : S) {
            if (isalpha(c)) {
                while (!isalpha(S[i])) {
                    --i;
                }
                result.push_back(S[i]);
                --i;
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
