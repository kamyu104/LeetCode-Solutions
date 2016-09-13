// Time:  O(logn), n is the max of (x, y)
// Space: O(1)

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z <= x + y && z % gcd(x, y) == 0);
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
