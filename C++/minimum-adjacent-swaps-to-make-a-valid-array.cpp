// Time:  O(n)
// Space: O(1)

// array, greedy
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        const int min_idx = distance(cbegin(nums), min_element(cbegin(nums), cend(nums)));
        const int max_idx = (size(nums) - 1) - distance(crbegin(nums), max_element(crbegin(nums), crend(nums)));
        return ((size(nums) - 1) - max_idx) + min_idx - static_cast<int>(max_idx < min_idx);
    }
};
