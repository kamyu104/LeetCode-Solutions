// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        return accumulate(cbegin(nums), cend(nums), 0,
                          [](const auto& a, const auto& b) {
                              return a | b;
                          });
    }
};
