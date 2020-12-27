// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string maximumBinaryString(string binary) {
        int zeros = 0, ones = 0;
        for (auto& c : binary) {
            if (c == '0') {
                ++zeros;
            } else if (zeros == 0) {
                ++ones;
            }
            c = '1';
        }
        if (ones != size(binary)) {
            binary[ones + zeros - 1] = '0';
        }
        return binary;
    }
};
