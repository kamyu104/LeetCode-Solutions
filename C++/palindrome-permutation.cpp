// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bit;
        for (const auto& c : s) {
            bit.flip(c);
        }
        return bit.count() < 2;
    }
};
