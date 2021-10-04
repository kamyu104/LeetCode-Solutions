// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = 0, max_count = 0;
        unordered_map<char, int> count;
        for (int i = 0; i < size(answerKey); ++i) {
            ++count[answerKey[i]];
            max_count = max(max_count, count[answerKey[i]]);
            if (result - max_count >= k) {
                --count[answerKey[i - result]];
            } else {
                ++result;
            }
        }
        return result;
    }
};
