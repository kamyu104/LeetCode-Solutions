// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int result = 0;
        for (int i = 0; (i + 1) + result < size(word); ++i) {
            if (abs(word[(i + 1) + result] - word[i + result]) <= 1) {
                ++result;
            }
        }
        return result;
    }
};
