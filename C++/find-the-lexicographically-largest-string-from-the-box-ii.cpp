// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int idx = 0;
        for (int i = 1, l = 0; i < size(word); ++i) {
            if (word[i] == word[idx + l]) {
                ++l;
            } else if (word[i] < word[idx + l]) {
                l = 0;
            } else if (word[i] > word[idx + l]) {
                if (word[i - l] >= word[i]) {
                    idx = i - l;
                } else {
                    idx = i;
                }
                l = 0;
            }
        }
        return word.substr(idx, (size(word) - max((numFriends - 1) - idx, 0)) - idx);
    }
};
