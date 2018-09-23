// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        return max(0, *max_element(A.cbegin(), A.cend()) -
                      *min_element(A.cbegin(), A.cend()) -
                      2 * K);
    }
};
