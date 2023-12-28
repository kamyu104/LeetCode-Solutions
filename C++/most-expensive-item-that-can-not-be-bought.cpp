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
