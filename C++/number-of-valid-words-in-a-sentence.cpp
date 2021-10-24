// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countValidWords(string sentence) {
        int result = 0, token = 0, hyphen = 0;
        for (int i = 0; i <= size(sentence); ++i) {
            if (i == size(sentence) || sentence[i] == ' ') {
                if (token == 1) {
                    ++result;
                }
                token = hyphen = 0;
                continue;
            }
            if (isdigit(sentence[i]) ||
                (string("!.,").find(sentence[i]) != string::npos && !(i == size(sentence) - 1 || sentence[i + 1] == ' ')) ||
                (sentence[i] == '-' && !(hyphen == 0 && 0 < i && i < size(sentence) && isalpha(sentence[i - 1]) && isalpha(sentence[i + 1])))) {
                token = -1;
                continue;
            }
            if (token == 0) {
                token = 1;
            }
            if (sentence[i] == '-') {
                hyphen = 1;
            }
        }
        return result;
    }
};
