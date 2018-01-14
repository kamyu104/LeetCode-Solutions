// Time:  O(log(R - L)) = O(1)
// Space: O(1)

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        static const unordered_set<uint32_t> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int result = 0;
        for (int i = L; i <= R; ++i) {
            result += primes.count(bitCount(i));
        }
        return result;
    }

private:
    int bitCount(uint32_t n) {
        int count = 0;
        for (; n; n &= n - 1) {
            ++count;
        }
        return count;
    }
};
