// Time:  O(n + w^2), n = w * l,
//                    n is the length of S,
//                    w is the number of words,
//                    l is the average of word lengths
// Space: O(l)

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string result, word;
        int count = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != ' ') {
                word.push_back(S[i]);
                if (i != S.length() - 1) {
                    continue;
                }
            }
            if (!vowel.count(word.front())) {
                word.push_back(word.front());
                word = word.substr(1);
            }
            word += "ma";
            word += string(++count, 'a');
            result += word;
            result += " ";
            word.clear();
        }
        result.pop_back();
        return result;
    }
};
