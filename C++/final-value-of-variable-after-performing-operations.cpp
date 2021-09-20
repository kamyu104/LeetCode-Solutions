// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        return accumulate(cbegin(operations), cend(operations), 0,
                          [](const auto& total, const auto& x) {
                              return total + ((x[1] == '+') ? 1 : -1);
                          });
    }
};
