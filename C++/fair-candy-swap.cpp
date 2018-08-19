// Time:  O(m + n)
// Space: O(m + n)

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.cbegin(), A.cend(), 0) -
                    accumulate(B.cbegin(), B.cend(), 0)) / 2;
        unordered_set<int> setA(A.begin(), A.end());
        for (const auto& b: B) {
            if (setA.count(b + diff)) {
                return {b + diff, b};
            }
        }
        return {};
    }
};
