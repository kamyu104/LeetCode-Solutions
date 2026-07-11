// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minOperations(string s1, string s2) {
        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int result = 0;
        for (int i = 0; i < size(s1); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (s1[i] == '0') {
                ++result;
            } else if (i + 1 < size(s1)) {
                result += s1[i + 1] == '1' ? 1 : 2;
                s1[i + 1] = '0';
            } else {
                result += 2;
            }
        }
        return result;
    }
};
