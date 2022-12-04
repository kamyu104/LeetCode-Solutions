// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < size(sentence); ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        return sentence.front() == sentence.back();
    }
};
