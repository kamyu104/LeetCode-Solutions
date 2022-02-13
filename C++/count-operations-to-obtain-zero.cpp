// Time:  O(log(min(m, n)))
// Space: O(1)

// gcd-like solution
class Solution {
public:
    int countOperations(int num1, int num2) {
        int result = 0;
        while (num2) {
            result += num1 / num2;
            tie(num1, num2) = make_pair(num2, num1 % num2);
        }
        return result;
    }
};
