// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int right = distance(A.cbegin(), lower_bound(A.cbegin(), A.cend(), 0));
        int left = right - 1;
        vector<int> result;
        while (0 <= left || right < A.size()) {
            if (right == A.size() ||
                (0 <= left && A[left] * A[left] < A[right] * A[right])) {
                result.emplace_back(A[left] * A[left]);
                --left;
            } else {
                result.emplace_back(A[right] * A[right]);
                ++right;
            }
        }
        return result;
    }
};
