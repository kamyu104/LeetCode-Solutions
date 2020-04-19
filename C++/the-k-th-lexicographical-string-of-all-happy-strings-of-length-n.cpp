// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string getHappyString(int n, int k) {
        auto base = 1 << (n - 1);
        if (k > 3 * base) {
            return "";
        }
        string result = string(1, 'a' + (k - 1) / base);
        while (base > 1) {
            k -=  ((k - 1) / base) * base;
            base >>= 1;
            result += (k - 1) / base == 0
                      ? (result.back() != 'a' ? 'a' : 'b')
                      : (result.back() != 'c' ? 'c' : 'b');
        }
        return result;
    }
};
