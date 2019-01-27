// Time:  O(a + b)
// Space: O(1)

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result;
        bool put_A = false;
        while (A || B) {
            if (result.length() >= 2 &&
                result.back() == result[result.length() - 2]) {
                put_A = (result.back() == 'b');
            } else {
                put_A = (A >= B);
            }
            if (put_A) {
                --A;
                result.push_back('a');
            } else {
                --B;
                result.push_back('b');
            }
        }
        return result;
    }
};
