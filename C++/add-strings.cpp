// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;

        for (int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
             i >= 0 || j >= 0 || carry;
             carry /= 10) {

            if (i >= 0) {
                carry += num1[i--] - '0';
            }
            if (j >= 0) {
                carry += num2[j--] - '0';
            }
            result += to_string(carry % 10);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
