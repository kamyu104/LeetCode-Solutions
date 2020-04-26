// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxScore(string s) {
        int result = 0, zeros = 0, ones = 0;
        for (int i = 1; i + 1 < s.length(); ++i) {
            (s[i] == '0') ? ++zeros : ++ones;
            result = max(result, zeros - ones);
        }
        return result + ones + (s.front() == '0') + (s.back() == '1');
    }
};
