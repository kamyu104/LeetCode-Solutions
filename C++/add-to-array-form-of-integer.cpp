// Time:  O(n + logk)
// Space: O(1)

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int carry = K, i = 0;
        A[i] += carry;
        carry = A[i] / 10;
        A[i] %= 10;
        while (carry) {
            ++i;
            if (i < A.size()) {
                A[i] += carry;
            } else {
                A.emplace_back(carry);
            }
            carry = A[i] / 10;
            A[i] %= 10;
        }
        reverse(A.begin(), A.end());
        return A;
    }
};
