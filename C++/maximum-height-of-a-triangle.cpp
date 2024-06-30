// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        const auto& f = [](int x, int y) {
            // odd level:
            // (1+h)*((1+h)//2)//2 <= x
            // => h <= int(2*x**0.5)-1
            // even level:
            // (2+h)*(h//2)//2 <= y
            // => h <= int((4*y+1)**0.5)-1
            const int a = static_cast<int>(2 * sqrt(x)) - 1;
            const int b = static_cast<int>(sqrt(4 * y + 1)) - 1;
            return min(a, b) + (a != b ? 1 : 0);
        };
    
        return max(f(red, blue), f(blue, red));
    }
};

// Time:  O(sqrt(n))
// Space: O(1)
// simulation
class Solution2 {
public:
    int maxHeightOfTriangle(int red, int blue) {
        const auto& f = [](int x, int y) {
            int h = 0;
            for (; x >= h + 1; swap(x, y)) {
                x -= ++h;
            } 
            return h;
        };
    
        return max(f(red, blue), f(blue, red));
    }
};
