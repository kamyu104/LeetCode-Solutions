// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int right = 0;
        while (right < A.size() && A[right] < 0) {
            ++right;
        }
        int left = right - 1;

        vector<int> result;
        while (0 <= left && right < A.size()) {
            if (A[left] * A[left] < A[right] * A[right]) {
                result.emplace_back(A[left] * A[left]);
                --left;
            } else {
                result.emplace_back(A[right] * A[right]);
                ++right;
            }
        }

        while (left >= 0) {
            result.emplace_back(A[left] * A[left]);
            --left;
        }
        while (right < A.size()) {
            result.emplace_back(A[right] * A[right]);
            ++right;
        }

        return result;
    }
};
