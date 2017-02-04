// Time:  O((logn)^2)
// Space: O(1)

class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoll(n);
        for (int l = log(num) / log(2); l >= 2; --l) {
            unsigned long long b = pow(num, 1.0 / l), sum = 0, curr = 1;
            for (int i = 0; i <= l; ++i, curr *= b) {
                sum += curr;
            }
            if (sum == num) {
                return to_string(b);
            }
        }  
        return to_string(num - 1);
    }
};
