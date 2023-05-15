// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(cbegin(derived), cend(derived), 0, [](const auto& total, const auto& x) {
            return total ^ x;
        }) == 0;
    }
};
