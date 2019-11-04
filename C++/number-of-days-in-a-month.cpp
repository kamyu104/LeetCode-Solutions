// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int numberOfDays(int Y, int M) {
        const auto& leap = (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0)) ? 1 : 0;
        return (M == 2) ? 28 + leap : 31 - (M - 1) % 7 % 2;
    }
};
