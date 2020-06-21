// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int xorOperation(int n, int start) {
        return int(n % 2 && start % 2) + 2 * xorNums(n, start / 2);
    }

private:    
    int xorNums(int n, int start) {
        return (start % 2)
               ? start ^ xorNumsBeginEven(n - 1, start + 1)
               : xorNumsBeginEven(n, start);
    }
    
    int xorNumsBeginEven(int n, int start) {
        assert(start % 2 == 0);
        // 2*i ^ (2*i+1) = 1
        return ((n / 2) % 2) ^ ((n % 2) ? (start + n - 1) : 0);
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = start + 2 * n - 2; i >= start; i -= 2) {
            result ^= i;
        }
        return result;
    }
};
