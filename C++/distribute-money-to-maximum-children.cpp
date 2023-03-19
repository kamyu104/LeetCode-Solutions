// Time:  O(1)
// Space: O(1)

// greedy
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children * 1) {
            return -1;
        }
        money -= children * 1;
        const int q = money / 7, r = money % 7;
        return min(q, children) - static_cast<int>(q > children || (q == children && r != 0) || (q == children - 1 && r == 3));
    }
};

// Time:  O(1)
// Space: O(1)
// greedy
class Solution2 {
public:
    int distMoney(int money, int children) {
        if (money < children * 1) {
            return -1;
        }
        money -= children * 1;
        const int q = money / 7, r = money % 7;
        if (q > children) {
            return children - 1;
        }
        if (q == children) {
            return q - static_cast<int>(r != 0);
        }
        if (q == children - 1) {
            return q - static_cast<int>(r == 3);
        }
        return q;
    }
};
