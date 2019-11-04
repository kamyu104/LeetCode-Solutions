// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return solution(s);
    }
private:
    int solution(const string& s) {
        unordered_map<char, int> lastOccurrence;
        int startIdx = 0, result = 0;
        for (auto i = 0; i < s.size(); ++i) {
            if (lastOccurrence.find(s[i]) != lastOccurrence.cend() && lastOccurrence[s[i]] >= startIdx) {
                startIdx = lastOccurrence[s[i]];
            }
            lastOccurrence[s[i]] = i;
            result = max(result, i - startIdx);
        }
        return result;
    }
};