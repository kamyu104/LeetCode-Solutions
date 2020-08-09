// Time:  O(10 * n)
// Space: O(1024)

class Solution {
public:
    int longestAwesome(string s) {
        static const int ALPHABET_SIZE = 10;
        int result = 0, mask = 0;
        vector<int> lookup(1 << ALPHABET_SIZE, s.length());
        lookup[0] = -1;
        for (int i = 0; i < s.length(); ++i) {
            mask ^= 1 << (s[i] - '0');
            if (lookup[mask] == s.length()) {
                lookup[mask] = i;
            }
            result = max(result, i - lookup[mask]);  // no middle
            for (int d = 0; d < ALPHABET_SIZE; ++d) {
                result = max(result, i - lookup[mask ^ (1 << d)]);  // as middle
            }
            lookup[mask] = min(lookup[mask], i);
        }
        return result;
    }
};
