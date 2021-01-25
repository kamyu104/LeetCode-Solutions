// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int minimumBoxes(int n) {
        // find max h s.t. sum(k*(k+1)//2 for k in xrange(1, h+1)) <= n
        // => find max h s.t. h*(h+1)*(h+2)//6 <= n
        int h = pow(6.0 * n, 1.0 / 3);
        if (int64_t(h) * (h + 1) * (h + 2) / 6 > n) {
            // (h-1)*h*(h+1) < h^3 <= 6n < h*(h+1)*(h+2) < (h+1)^3
            --h;
        }
        n -= int64_t(h) * (h + 1) * (h + 2) / 6;
        int d = ceil((-1 + sqrt(1 + 8 * n)) / 2);  // find min d s.t. d*(d+1)//2 >= n
        return h * (h + 1) / 2 + d;
    }
};
