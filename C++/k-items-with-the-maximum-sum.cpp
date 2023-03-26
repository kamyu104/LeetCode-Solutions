// Time:  O(1)
// Space: O(1)

// greedy, math
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(numOnes, k) - max(k - numOnes - numZeros, 0);
    }
};
