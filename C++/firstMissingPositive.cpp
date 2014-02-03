// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            int i;
            bucketSort(A, n);
            for(i = 0; i < n && A[i] == i + 1; ++i);
            return i + 1;
        }

    private:
        void bucketSort(int A[], int n) {
            for(int i = 0; i < n; ++i) {
                for (; A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1];) {
                    swap(A[i], A[A[i] - 1]);
                }
            }
        }
};
