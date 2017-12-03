// Time:  O(logn) = O(1)
// Space: O(logn) = O(1)

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int leftmost_inverted_idx = s.length();
        for (int i = s.length() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                leftmost_inverted_idx = i;
                --s[i - 1];
            }
        }
        for (int i = leftmost_inverted_idx; i < s.length(); ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
