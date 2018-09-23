// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int result = A.back() - A.front();
        for (int i = 0; i < A.size() - 1; ++i) {
            result = min(result,
                         max(A.back() - K, A[i] + K) - 
                         min(A.front() + K, A[i + 1] - K));
        }
        return result;
    }
};
