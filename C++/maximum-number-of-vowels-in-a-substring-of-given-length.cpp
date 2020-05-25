// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxVowels(string s, int k) {
        static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int result = 0, curr = 0;
        for (int i = 0; i < s.length(); ++i) {
            curr += vowels.count(s[i]);
            if (i >= k) {
                curr -= vowels.count(s[i - k]);
            }
            result = max(result, curr);
        }
        return result;
    }
};
