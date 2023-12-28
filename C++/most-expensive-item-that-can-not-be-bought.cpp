// Time:  O(1)
// Space: O(1)

// Chicken McNugget Theorem
class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        // reference:
        // - https://en.wikipedia.org/wiki/Coin_problem
        // - https://mikebeneschan.medium.com/the-chicken-mcnugget-theorem-explained-2daca6fbbe1e
        return primeOne * primeTwo - primeOne - primeTwo;
    }
};

// Time:  O(p1 * p2)
// Space: O(p1 + p2)
// dp
class Solution2 {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        vector<int> dp(max(primeOne, primeTwo));
        dp[0] = true;
        const int w = max(primeOne, primeTwo);
        int result = 1;
        for (int i = 2; i < primeOne * primeTwo; ++i) {
            dp[i % w] = dp[((i - primeOne) % w + w) % w] || dp[((i - primeTwo) % w + w) % w];
            if (!dp[i % w]) {
                result = i;
            }
        }
        return result;
    }
};
