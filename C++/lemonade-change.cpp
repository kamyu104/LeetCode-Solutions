// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        static const vector<int> coins = {20, 10, 5};
        unordered_map<int, int> counts;
        for (const auto& bill : bills) {
            ++counts[bill];
            auto change = bill - coins.back();
            for (const auto& coin : coins) {
                if (change == 0) {
                        break;
                }
                if (change >= coin) {
                    const auto count = min(counts[coin], change / coin);
                    counts[coin] -= count;
                    change -= coin * count;
                }
            }
            if (change != 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
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
