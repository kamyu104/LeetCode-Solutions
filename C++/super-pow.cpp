// Time:  O(n), n is the size of b.
// Space: O(1)

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (const auto& digit : b) {
            result = myPow(result, 10, 1337) * myPow(a, digit, 1337) % 1337;
        }
        return result;
    }

private:
    int myPow(int a, int n, int b) {
        int result = 1;
        int x = a % b;
        while (n) {
            if (n & 1) {
                result = result * x % b;
            }
            n >>= 1;
            x = x * x % b;
        }
        return result % b;
    }
};
