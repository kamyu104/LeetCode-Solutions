// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        const auto& total = accumulate(A.cbegin(), A.cend(), 0);
        if (total % 3 != 0) {
            return false;
        }
        int curr = 0, parts = 0;
        for (const auto& x : A) {
            curr += x;
            if (curr == total / 3) {
                ++parts, curr = 0;
            }
        }
        return parts >= 3;
    }
};
