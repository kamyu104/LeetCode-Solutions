// Time:  O(1)
// Space: O(1)

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // let the number of jumbo burger be x, the number of small burger be y:
        //   4x + 2y = t
        //   x + y = c
        //   =>
        //   x = t/2-c
        //   y = 2c-t/2
        // since x, y are natural numbers
        //   => t/2 is integer, t/2-c >= 0, 2c-t/2 >= 0
        //   => t%2 == 0, 2c <= t <= 4c
        if (tomatoSlices % 2 == 0 &&
            2 * cheeseSlices <= tomatoSlices &&
            tomatoSlices <= 4*cheeseSlices) {
            return {tomatoSlices / 2 - cheeseSlices, 2 * cheeseSlices - tomatoSlices / 2};
        }
        return {};
    }
};
