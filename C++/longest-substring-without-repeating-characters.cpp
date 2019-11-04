// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_occurrence;
        int result = 0, starting_idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (last_occurrence.count(s[i])) {
                starting_idx = max(starting_idx, last_occurrence[s[i]] + 1);
            }
            last_occurrence[s[i]] = i;
            result = max(result, i - starting_idx + 1);
        }
        return result;
    }
};
