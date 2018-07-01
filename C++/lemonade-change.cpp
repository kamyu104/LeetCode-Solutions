// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (const auto& bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (!five) {
                    return false;
                }
                --five;
                ++ten;
            } else {
                if (five && ten) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
