// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, size_t> last_occurrence;
        size_t starting_idx = 0;
        size_t result = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (last_occurrence.count(s[i]) &&
                last_occurrence[s[i]] >= starting_idx) {
                result = max(result, i - starting_idx);
                starting_idx = last_occurrence[s[i]] + 1;
            }
            last_occurrence[s[i]] = i;
        }
        result = max(result, s.length() - starting_idx);
        return result;
    }
};
