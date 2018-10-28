// Time:  O(n)
// Space: O(1)

// Two pointers solution.
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int result = 0;
        int left = 0, right = 0, sum_left = 0, sum_right = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (sum_left += A[i];
                 left < i && sum_left > S;
                 ++left) {
                sum_left -= A[left];
            }
            for (sum_right += A[i];
                 right < i && (sum_right > S || (sum_right == S && !A[right]));
                 ++right) {
                sum_right -= A[right];
            }
            if (sum_left == S) {
                result += right - left + 1;
            }
        }
        return result;
    }
};
