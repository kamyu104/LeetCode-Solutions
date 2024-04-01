// Time:  O(sqrt(n))
// Space: O(1)

// simulation
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange++;
            ++result;
            ++numBottles;
        }
        return result;
    }
};
