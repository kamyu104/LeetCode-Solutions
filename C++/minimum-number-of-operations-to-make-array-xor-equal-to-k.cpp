// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return __builtin_popcount(accumulate(cbegin(nums), cend(nums), k, [](int accu, int x) {
            return accu ^ x;
        }));
    }
};
