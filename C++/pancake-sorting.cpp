// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for (int n = A.size(); n > 0; --n) {
            int i;
            for (i = 0; A[i] != n; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            result.emplace_back(i + 1);
            reverse(A.begin(), A.begin() + n);
            result.emplace_back(n);
        }
        return result;
    }
};
