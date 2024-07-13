// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    bool divisorGame(int n) {
        // 1. if we get an even, we can choose x = 1
        //    to make the opponent always get an odd
        // 2. if the opponent gets an odd, he can only choose x = 1 or other odds
        //    and we can still get an even
        // 3. at the end, the opponent can only choose x = 1 and we win
        // 4. in summary, we win if only if we get an even and 
        //    keeps even until the opponent loses
        return n % 2 == 0;
    }
};

// Time:  O(n^3/2)
// Space: O(n)
// memoization
class Solution2 {
public:
    bool divisorGame(int n) {
        vector<int> lookup(n + 1, -1);
        const function<int (int)> memoization = [&](int n) {
            if (lookup[n] == -1) {
                int result = 0;
                for (auto i = 1; i * i <= n; ++i) {
                    if (n % i) {
                        continue;
                    }
                    if (i != n && !memoization(n - i)) {
                        result = 1;
                        break;
                    }
                    const int j = n / i;
                    if (j == i) {
                        continue;
                    }
                    if (j != n && !memoization(n - j)) {
                        result = 1;
                        break;
                    }
                }
                lookup[n] = result;
            }
            return lookup[n];
        };

        return memoization(n);
    }
};
