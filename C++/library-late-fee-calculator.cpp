// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        return accumulate(cbegin(daysLate), cend(daysLate), 0, [](const auto& total, const auto& x) {
            return total + (x == 1 ? x : (x >= 6 ? 3 * x : 2 * x));
        });
    }
};
