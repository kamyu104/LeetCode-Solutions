// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(),
                          0, std::bit_xor<int>()) == 0 ||
               nums.size() % 2 == 0;
    }
};
