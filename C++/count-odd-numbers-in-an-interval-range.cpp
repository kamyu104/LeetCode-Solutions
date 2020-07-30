// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - ((low - 1) + 1) / 2;
    }
};
