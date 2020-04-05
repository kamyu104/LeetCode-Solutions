// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numSteps(string s) {
        int result = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            if (s[i] - '0' + carry == 1) {
                carry = 1;  // once it was set, it would keep carrying forever
                result += 2;
            } else {
                ++result;
            }
        }
        return result + carry;
    }
};
