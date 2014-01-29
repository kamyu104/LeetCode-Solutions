// Time Complexity: O(logn)
// Space Complexity: O(logn)

class Solution {
    public:
        double pow(double x, int n) {
            if(n < 0)
                return 1.0 / power(x, -n); // be careful: -1 * -2147483648 is still -2147483648
            else
                return power(x, n);
        }

    private:
        double power(double x, int n) {
            if(n == 0)
                return 1;
            double v = power(x, n / 2);

            if(n % 2 != 0)
                return v * v * x;
            else
                return  v * v;
        }
};
