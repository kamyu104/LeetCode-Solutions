// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        const int mn = ranges::min(nums);
        return all_of(cbegin(nums), cend(nums), [&](const auto& x) { return x % mn == 0; })
               ? (count(cbegin(nums), cend(nums), mn) + 1) / 2
               : 1;
    }
};
