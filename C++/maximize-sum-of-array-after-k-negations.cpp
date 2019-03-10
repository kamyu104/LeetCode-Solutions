// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K) {
            A[i] = -A[i];
        }
        return accumulate(A.cbegin(), A.cend(), 0) -
               (K % 2) * *min_element(A.cbegin(), A.cend()) * 2;
    }
};
