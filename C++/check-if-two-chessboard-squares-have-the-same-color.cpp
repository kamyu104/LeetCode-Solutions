// Time:  O(1)
// Space: O(1)

// math, parity
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        const auto& parity = [](const auto& a) {
            int result = 0;
            for (const auto& x : a) {
                result = (result + x) % 2;
            }
            return result;
        };

        return parity(coordinate1) == parity(coordinate2);
    }
};
