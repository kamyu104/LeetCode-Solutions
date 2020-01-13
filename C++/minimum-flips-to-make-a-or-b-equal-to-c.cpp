// Time:  O(31)
// Space: O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int diff = (a | b) ^ c;
        return number_of_1_bits(diff) + number_of_1_bits(diff & (a & b));
    }

private:
    int number_of_1_bits(int n) {
        int result = 0;
        for (; n; n &= n - 1, ++result);
        return result;
    }
};

// Time:  O(31)
// Space: O(1)
class Solution2 {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        for (int i = 0; i < 31; ++i) {
            int a_i = a & 1, b_i = b & 1, c_i = c & 1;
            if ((a_i | b_i) != c_i) {
                result += (a_i == b_i && b_i == 1) ? 2 : 1;
            }
            a = a >> 1, b = b >> 1, c = c >> 1;
        }
        return result;
    }
};
