// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        for (; i < size(s); ++i) {
            if (s[i] != 'a') {
                break;
            }
        }
        if (i == size(s)) {
            s.back() = 'z';
        } else {
            for (; i < size(s); ++i) {
                if (s[i] == 'a') {
                    break;
                }
                --s[i];
            }
        }
        return s;
    }
};
