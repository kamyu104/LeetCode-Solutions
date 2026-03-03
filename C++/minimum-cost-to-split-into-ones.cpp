// Time:  O(1)
// Space: O(1)

// combinatorics
class Solution {
public:
    int minCost(int n) {
        const auto& nC2 = [](int n) {
            return n * (n - 1) / 2;
        };

        return nC2(n);
    }
};
