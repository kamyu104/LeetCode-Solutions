// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        return accumulate(cbegin(nums), cend(nums), 0, [](const auto& total, const auto& x) {
            return total | (x % 2 == 0 ? x : 0);
        });
    }
};
