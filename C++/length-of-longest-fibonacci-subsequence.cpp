// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> lookup(A.cbegin(), A.cend());
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int  x = A[i], y = A[j], l = 2;
                while (lookup.count(x + y)) {
                    y = x + y, x = y - x, ++l;
                }
                result = max(result, l);
            }
        }
        return result > 2 ? result : 0;
    }
};
