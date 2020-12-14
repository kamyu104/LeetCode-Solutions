// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        vector<int> dp(size(boxes) + 1);
        int left = 0, cost = 1, curr = 0;
        for (int right = 0; right < size(boxes); ++right) {
            if (right == 0 || boxes[right][0] != boxes[right - 1][0]) {
                ++cost;
            }
            curr += boxes[right][1];
            while (right - left + 1 > maxBoxes ||
                   curr > maxWeight ||
                   (left + 1 < right + 1 && dp[left + 1] == dp[left])) {  // greedily drop box to make cost as smaller as possible
                curr -= boxes[left][1];
                if (boxes[left + 1][0] != boxes[left][0]) {
                    --cost;
                }
                ++left;
            }
            dp[right + 1] = dp[(left - 1) + 1] + cost;
        }
        return dp[size(boxes)];
    }
};
