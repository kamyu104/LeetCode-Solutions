// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        int result = INF;
        for (int k = 0, i = -1, j = -1; k < size(nums); ++k) {
            if (nums[k] == 0) {
                continue;
            }
            if (nums[k] == 1) {
                i = k;
            } else {
                j = k;
            }
            if (i != -1 && j != -1) {
                result = min(result, abs(i - j));
            }
        }
        return result != INF ? result : -1;
    }
};
