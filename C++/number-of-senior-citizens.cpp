// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int countSeniors(vector<string>& details) {
        return accumulate(cbegin(details), cend(details), 0, [](const auto& total, const auto& x) {
            return total + static_cast<int>(x.substr(11, 2) > "60");
        });
    }
};
