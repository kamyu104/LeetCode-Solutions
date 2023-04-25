// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int addMinimum(string word) {
        int cnt = 0;
        for (int i = 0; i < size(word); ++i) {
            cnt += static_cast<int>(i - 1 < 0 || word[i - 1] >= word[i]);
        }
        return 3 * cnt - size(word);
    }
};
