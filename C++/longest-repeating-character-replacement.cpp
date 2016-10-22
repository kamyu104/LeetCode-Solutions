// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cache(26);

        int i = 0, j = 0, times = k, res = 0;
        for (; j < s.size(); ++j) {
            ++cache[s[j] - 'A'];
            if (s[j] != s[i]) {
                --times;
                if (times < 0) {
                    res = max(res, j - i);
                    while (i < j && k - (j - i + 1 - cache[s[i] - 'A']) < 0) {
                        --cache[s[i++] - 'A'];
                    }
                    times = k - (j - i + 1 - cache[s[i] - 'A']);
                }
            }
        }
        return max(res, j - i + min(i, times));
    }
};
