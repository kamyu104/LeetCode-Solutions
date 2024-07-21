// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        for (int i = 0, curr = 0; i < size(s); ++i) {
            if (s[i] == '1') {
                ++curr;
            } else if (i + 1 == size(s) || s[i + 1] == '1') {
                result += curr;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// greedy
class Solution2 {
public:
    int maxOperations(string s) {
        int result = 0;
        for (int i = 0, curr = 0; i < size(s); ++i) {
            if (s[i] != '1') {
                continue;
            }
            ++curr;
            if (i + 1 < size(s) && s[i + 1] == '0') {
                result += curr;
            }
        }
        return result;
    }
};
