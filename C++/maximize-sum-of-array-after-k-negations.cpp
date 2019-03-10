// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(1)

// quick select solution
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        nth_element(A.begin(), A.begin() + K, A.end());
        int remain = K;
        for (int i = 0; i < K; ++i) {
            if (A[i] < 0) {
                A[i] = -A[i];
                --remain;
            }
        }
        return accumulate(A.cbegin(), A.cend(), 0) -
               (remain % 2) * *min_element(A.cbegin(), A.cend()) * 2;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int remain = K;
        for (int i = 0; i < K && A[i] < 0; ++i) {
            A[i] = -A[i];
            --remain;
        }
        return accumulate(A.cbegin(), A.cend(), 0) -
               (remain % 2) * *min_element(A.cbegin(), A.cend()) * 2;
    }
};
