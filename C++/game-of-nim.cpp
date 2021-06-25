// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool nimGame(vector<int>& piles) {
        return accumulate(cbegin(piles), cend(piles), 0, bit_xor<int>());
    }
};
