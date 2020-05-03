// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int maxDiff(int num) {
        const auto& digits = to_string(num);
        char b;
        for (const auto& c : digits) {
            if (c < '9') {
                b = c;
                break;
            }
        }
        char a;
        if (digits[0] != '1') {
            a = digits[0];
        } else {
            for (const auto& c : digits) {
                if (c > '1') {
                    a = c;
                    break;
                }
            }
        }
        string big(digits), small(digits);
        replace(begin(big), end(big), b, '9');
        replace(begin(small), end(small), a, digits[0] != '1' ? '1' : '0');
        return stoi(big) - stoi(small);
    }
};
