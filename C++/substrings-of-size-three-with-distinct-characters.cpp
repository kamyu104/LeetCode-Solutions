// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countGoodSubstrings(string s) {
        static const int K = 3;

        int result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < size(s); ++i) {
            if (i >= K) {
                if (--count[s[i - K]] == 0) {
                    count.erase(s[i - K]);
                }
            }
            ++count[s[i]];
            if (size(count) == K) {
                ++result;
            }
        }
        return result;
    }
};
