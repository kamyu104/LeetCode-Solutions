// Time:  O(n)
// Spce:  O(1)

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        static const int M = 1e9 + 7;
        sort(A.begin(), A.end());
        // sum(A[i] * (2^i - 2^(len(A)-1-i))), i = 0..len(A)-1
        // <=>
        // sum(((A[i] - A[len(A)-1-i]) * 2^i), i = 0..len(A)-1
        int64_t result = 0l, c = 1l;
        for (int i = 0; i < A.size(); ++i, c = (c << 1) % M) {
            result = (result + (A[i] - A[A.size() - 1 - i]) * c % M) % M;
        }
        return (result + M) % M;
    }
};
