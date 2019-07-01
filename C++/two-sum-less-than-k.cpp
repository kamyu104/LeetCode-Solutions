// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int result = -1;
        int left = 0, right = A.size() - 1;
        while (left < right) {
            if (A[left] + A[right] >= K) {
                --right;
            } else {
                result = max(result, A[left] + A[right]);
                ++left;
            }
        }
        return result;
    }
};
