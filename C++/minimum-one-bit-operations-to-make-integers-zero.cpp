// Time:  O(logn)
// Space: O(1)

// reference: https://en.wikipedia.org/wiki/Gray_code
class Solution {
public:
    int minimumOneBitOperations(int n) {
        // [observation]
        // n    f(n)
        // 000    0
        // 001    1
        // 011    2
        // 010    3
        // 110    4
        // 111    5
        // 101    6
        // 100    7
        // f(0XX...X) + f(1XX...X) = f(100...0) implies n is a gray code
        // => f(n) is actually the inverse of gray code
        return gray_to_binary(n);
    }

private:
    int gray_to_binary(int n) {
        int result = 0;
        for (; n > 0; n >>= 1) {
            result ^= n;
        }
        return result;
    }
};

// Time:  O(logn)
// Space: O(1)
class Solution2 {
public:
    int minimumOneBitOperations(int n) {
        // [observation1]:
        // f(1) = 1
        // f(10) = 2 * f(1) + 1 = 3
        // f(100) = 2 * f(10) + 1 = 7
        // by mathematical induction
        // => f(2^k) = 2^(k+1)-1
        //
        // [observation2]:
        // n    f(n)
        // 000    0
        // 001    1
        // 011    2
        // 010    3
        // 110    4
        // 111    5
        // 101    6
        // 100    7
        // let pos be an array of positions where the bit is 1 in ascending order:
        // f(0XX...X) + f(1XX...X) = f(100...0)
        // f(1XX...X) = f(100...0) - f(0XX...X)
        //            = (2^(pos[k-1]+1)-1) - f(0XX...X)
        // by mathematical induction
        // => f(n) = (2^(pos[k-1]+1)-1) - (2^(pos[k-2])+1) + ... + (-1)^(k-1) * (2^(pos[0]+1)-1)
        int result = 0;
        for (; n > 0; n &= n - 1) {
            result = -(result + (n ^ (n - 1)));
        }
        return abs(result);
    }
};
