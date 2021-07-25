// Time:  O(n + logn + log(logn) + ...) = O(n)
// Space: O(1)

class Solution {
public:
    int getLucky(string s, int k) {
        int total = accumulate(cbegin(s), cend(s), 0,
                               [](const auto& total, const auto& x) {
                                   const auto num = x - 'a' + 1;
                                   return total + num / 10 + num % 10;
                               });
        while (--k && total > 9) {
            int new_total = 0;
            for (; total; total /= 10) {
                new_total += total % 10;
            }
            total = new_total;
        }
        return total;
    }
};
