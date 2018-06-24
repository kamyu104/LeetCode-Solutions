// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // explanation commented in the following solution
        return (p & -p) > (q & -q) ? 2 : (p & -p) < (q & -q) ? 0 : 1;
    }
};


// Time:  O(log(max(p, q))) = O(1) due to 32-bit integer
// Space: O(1)
class Solution2 {
public:
    int mirrorReflection(int p, int q) {
        const auto lcm = p * q / gcd(p, q);
        // let a = lcm / p, b = lcm / q
        if (lcm / p % 2 == 1) {
            if (lcm / q % 2 == 1) {
                return 1;  // a is odd, b is odd <=> (p & -p) == (q & -q)
            }
            return 2;  // a is odd, b is even <=> (p & -p) > (q & -q)
        }
        return 0;  // a is even, b is odd <=> (p & -p) < (q & -q)
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};
