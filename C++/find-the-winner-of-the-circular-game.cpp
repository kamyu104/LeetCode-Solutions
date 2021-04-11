// Time:  O(n)
// Space: O(1)

// bottom-up solution
class Solution {
public:
    int findTheWinner(int n, int k) {
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            idx = (idx + k) % (i + 1);
        }
        return idx + 1;
    }
};

// Time:  O(n)
// Space: O(n)
// top-down solution
class Solution2 {
public:
    int findTheWinner(int n, int k) {
        return f(0, n, k) + 1;
    }

private:
    int f(int idx, int n, int k) {
        if (n == 1) {
            return 0;
        }
        return (k + f((k + idx) % n, n - 1, k)) % n;
    }
};
