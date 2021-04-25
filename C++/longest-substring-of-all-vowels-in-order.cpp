// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int result = 0;
        for (int i = 0, len = 1, cnt = 1; i + 1 < size(word); ++i) {
            if (word[i] > word[i + 1]) {
                len = cnt = 1;
            } else {
                ++len;
                cnt += word[i] < word[i + 1];
            }
            if (cnt == 5) {
                result = max(result, len);
            }
        }
        return result;
    }
};
