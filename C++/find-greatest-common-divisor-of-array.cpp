// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(cbegin(nums), cend(nums)),
                   *max_element(cbegin(nums), cend(nums)));
    }
};
