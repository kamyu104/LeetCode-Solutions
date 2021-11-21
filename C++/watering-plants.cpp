// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int result = size(plants), can = capacity;
        for (int i = 0; i < size(plants); ++i) {
            if (can < plants[i]) {
                result += 2 * i;
                can = capacity;
            }
            can -= plants[i];
        }
        return result;
    }
};
