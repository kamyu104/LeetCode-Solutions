// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0, max_count = 0;
        unordered_map<char, int> count;
        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i]];
            max_count = max(max_count, count[s[i]]);
            if (result - max_count >= k) {
                --count[s[i - result]];
            } else {
                ++result;
            }
        }
        return result;
    }
};
