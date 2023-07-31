// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return accumulate(cbegin(hours), cend(hours), 0, [&](const auto& accu, const auto& x) {
            return accu + (x >= target ? 1 : 0);
        });
    }
};
