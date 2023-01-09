// Time:  O(n)
// Space: O(1)

// bit manipulation, math
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        return accumulate(cbegin(nums), cend(nums), 0, [](int a, int b) {
            return a ^ b;
        });
    }
};
