// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (size(sentence1) > size(sentence2)) {
            swap(sentence1, sentence2);
        }
        int count = 0;
        for (int i = 0; i <= size(sentence1); ++i) {
            char c1 = i != size(sentence1) ? sentence1[i] : ' ';
            char c2 = i != size(sentence2) ? sentence2[i] : ' ';
            if (c1 != c2) {
                break;
            }
            if (c1 == ' ') {
                ++count;
            }
        }
        for (int i = 0; i <= size(sentence1); ++i) {
            char c1 = i != size(sentence1) ? sentence1[size(sentence1) - 1 - i] : ' ';
            char c2 = i != size(sentence2) ? sentence2[size(sentence2) - 1 - i] : ' ';
            if (c1 != c2) {
                break;
            }
            if (c1 == ' ') {
                ++count;
            }
        }
        return count >= count_if(begin(sentence1), end(sentence1),
                                 [](char x) { return x == ' '; }) + 1;
    }
};
