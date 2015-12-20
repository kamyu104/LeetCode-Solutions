// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int bulbSwitch(int n) {
        // The number of full squares.
        return static_cast<int>(sqrt(n));
    }
};
