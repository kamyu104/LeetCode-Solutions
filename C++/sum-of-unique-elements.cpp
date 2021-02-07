// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        return accumulate(cbegin(count), cend(count), 0,
                          [](const auto& total, const auto& p) {
                              return total + (p.second == 1 ? p.first : 0);
                          });
    }
};
