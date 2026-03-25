// Time:  O(n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return ranges::min(nums1) % 2 == 1 || all_of(cbegin(nums1), cend(nums1), [](const auto& x) {
            return x % 2 == 0;
        });
    }
};
