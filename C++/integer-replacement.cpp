// Time:  O(logn)
// Space: O(1)

// Iterative solution.
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 2147483647) {
            return 2 + integerReplacement(n / 2 + 1);
        }

        int result = 0;
        while (n != 1) {
            const auto b = n & 3;
            if (n == 3) {
                --n;
            } else if (b == 3) {
                ++n;
            } else if (b == 1) {
                --n;
            } else {
                n /= 2;
            }
            ++result;
        }
        return result;
    }
};

// Time:  O(logn)
// Space: O(logn)
// Recursive solution
class Solution2 {
public:
    int integerReplacement(int n) {
        if (n == 2147483647) {
            return 2 + integerReplacement(n / 2 + 1);
        }

        if (n < 4) {
            switch (n % 4) {
                case 0: case 1: return 0;
                case 2: return 1;
                case 3: return 2;
            }
        }

        switch (n % 4) {
            case 0: case 2: return integerReplacement(n / 2) + 1;
            case 1: return integerReplacement((n - 1) / 4) + 3;
            case 3: return integerReplacement((n + 1) / 4) + 3;
        }
        return 0;
    }
};
