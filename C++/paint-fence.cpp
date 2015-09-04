// Time:  O(n)
// Space: O(1)

// DP with rolling window.
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return k;
        }
        vector<int> ways(3, 0);
        ways[0] = k;
        ways[1] = (k - 1) * ways[0] + k;
        for (int i = 2; i < n; ++i) {
            ways[i % 3] = (k - 1) * (ways[(i - 1) % 3] + ways[(i - 2) % 3]);
        }
        return ways[(n - 1) % 3];
    }
};

// Time:  O(n)
// Space: O(n)
// DP solution.
class Solution2 {
public:
    int numWays(int n, int k) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return k;
        }
        vector<int> ways(n, 0);
        ways[0] = k;
        ways[1] = (k - 1) * ways[0] + k;
        for (int i = 2; i < n; ++i) {
            ways[i] = (k - 1) * (ways[i - 1] + ways[i - 2]);
        }
        return ways[n - 1];
    }
};
