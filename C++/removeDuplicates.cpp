// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            const int occur = 2;
            if(n <= occur) return n;

            int cnt = occur;

            for(int i = occur; i < n; ++i) {
                if(A[i] != A[cnt - occur])
                    A[cnt++] = A[i];
            }

            return cnt;
        }
};
