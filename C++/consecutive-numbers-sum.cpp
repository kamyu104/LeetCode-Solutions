// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int result = 1;
        while (N % 2 == 0) {
            N /= 2;
        }
        for (int i = 3; i * i <= N; i += 2) {
            int count = 0;
            while (N % i == 0) {
                N /= i;
                ++count;
            }
            result *= count + 1;
        }
        if (N > 1) {
            result *= 2;
        }
        return result;
    }
};
