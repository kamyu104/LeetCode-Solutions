// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> dp_no_swap(2), dp_swap(2, 1);
        for (int i = 1; i < A.size(); ++i) {
            dp_no_swap[i % 2] = dp_swap[i % 2] = numeric_limits<int>::max();
            if (A[i - 1] < A[i] && B[i -1] < B[i]) {
                dp_no_swap[i % 2] = min(dp_no_swap[i % 2], dp_no_swap[(i - 1) % 2]);
                dp_swap[i % 2] = min(dp_swap[i % 2], dp_swap[(i - 1) % 2] + 1);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                dp_no_swap[i % 2] = min(dp_no_swap[i % 2], dp_swap[(i - 1) % 2]);
                dp_swap[i % 2] = min(dp_swap[i % 2], dp_no_swap[(i - 1) % 2] + 1);
            }
        }
        return min(dp_no_swap[(A.size() - 1) % 2], dp_swap[(A.size() - 1) % 2]);
    }
};
