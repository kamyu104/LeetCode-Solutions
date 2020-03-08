// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        static const string VOWELS = "aeiou";
        int result = 0, mask = 0;
        vector<int> lookup(1 << VOWELS.length(), -2);
        lookup[0] = -1;
        for (int i = 0; i < s.length(); ++i) {
            const auto& pos = VOWELS.find(s[i]);
            mask ^= pos != string::npos ? 1 << pos : 0;
            if (lookup[mask] == -2) {
                lookup[mask] = i;
            }
            result = max(result, i - lookup[mask]);
        }
        return result;
    }
};
