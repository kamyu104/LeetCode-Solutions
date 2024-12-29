// Time:  O(n * m)
// Space: O(m)

// greedy
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        const int m = size(word) - (numFriends - 1);
        const auto c = ranges::max(word);
        string result;
        for (int i = 0; i < size(word); ++i) {
            if (word[i] == c) {
                result = max(result, word.substr(i, m));
            }
        }
        return result;
    }
};
