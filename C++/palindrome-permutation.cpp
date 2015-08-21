// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bits;
        for (const auto& c : s) {
            bits.flip(c);
        }
        return bits.count() < 2;
    }
};
