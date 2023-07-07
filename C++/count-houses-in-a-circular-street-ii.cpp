// Time:  O(n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (!street->isDoorOpen()) {
            street->moveRight();
        }
        street->moveRight();
        int result = 0;
        for (int i = 1; i <= k; ++i) {
            if (street->isDoorOpen()) {
                street->closeDoor();
                result = i;
            }
            street->moveRight();
        }
        return result;
    }
};
