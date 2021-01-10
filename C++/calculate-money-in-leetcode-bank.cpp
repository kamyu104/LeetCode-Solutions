// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int totalMoney(int n) {
        static const int cost = 1, day = 7;
        static const auto arithmetic_sequence_sum =
            [](int a, int d, int n) {
                return (2 * a + (n - 1) * d) * n / 2;
            };

        int first_week_cost = arithmetic_sequence_sum(cost, cost, day);
        int week = n / day, remain_day = n % day;
        return arithmetic_sequence_sum(first_week_cost, cost * day, week) +
               arithmetic_sequence_sum(cost * (week + 1), cost, remain_day);
    }
};
