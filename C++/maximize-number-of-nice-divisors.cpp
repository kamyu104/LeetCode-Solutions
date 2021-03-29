// Time:  O(logn)
// Space: O(1)

// variant of "343. integer break"
class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        static const int mod = 1e9 + 7;
        
        // given a1 + a2 + ... + ak <= n, find max of a1 * a2 * ... * ak 
        // => given a1 + a2 + ... + ak = n, find max of a1 * a2 * ... * ak 
        // => ai is either 3 or 2, see proof in "343. integer break"
        if (primeFactors <= 3) {
            return primeFactors;
        }
        if (primeFactors % 3 == 0) {
            return powmod(3, primeFactors / 3, mod);  // 6 => 3 * 3
        }
        if (primeFactors % 3 == 1) {
            return 4 * powmod(3, (primeFactors - 4) / 3, mod) % mod;  // 4 => 2 * 2
        }
        return 2 * powmod(3, (primeFactors - 2) / 3, mod) % mod;  // 5 => 2 * 3
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};
