class Solution {
    public:
        void sortColors(int A[], int n) {
            int i0 = 0;
            int i2 = n-1;
            for(int i = 0; i < n && i0 <= i2 && i <= i2; i++) {
                while(A[i] != 1 && i0 <= i2 && i >= i0 && i<=i2) {
                    if(A[i] == 0) {
                        swap(A[i], A[i0++]);
                    }
                    else if(A[i] == 2) {
                        swap(A[i], A[i2--]);
                    }
                }
            }
        }
};
