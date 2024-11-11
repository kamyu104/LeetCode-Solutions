// Time:  O(logn)
// Space: O(1)

// brute force
class Solution {
public:
    int smallestNumber(int n, int t) {
        const auto& check = [&](int x) {
            int result = 1;
            while (x) {
                result = (result * (x % 10)) % t;
                x /= 10;
            }
            return result == 0; 
        };

        for (; !check(n); ++n);
        return n;
    }
};

