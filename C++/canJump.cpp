// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        bool canJump(int A[], int n) {
            int reach = 0;
            for(int i = 0; i <= reach && i < n; ++i) {
                reach = max(reach, i + A[i]);
            }
            return reach >= n - 1;
        }
};
