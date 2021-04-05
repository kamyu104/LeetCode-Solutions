// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
    }
};
