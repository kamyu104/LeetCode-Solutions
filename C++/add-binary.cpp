// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int result_length = max(a.length(), b.length()) ;

        int carry = 0;
        for (int i = 0; i < result_length; ++i) {
            int a_bit_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            int b_bit_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            int sum = carry + a_bit_i + b_bit_i;
            carry = sum / 2;
            sum %= 2;
            result.push_back('0' + sum);
        }
        if (carry) {
            result.push_back('0' + carry);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
