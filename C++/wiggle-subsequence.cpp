// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        int length = 1, up = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i] && (up == 0 || up == 1)) {
                ++length;
                up = -1;
            } else if (nums[i - 1] > nums[i] && (up == 0 || up == -1)) {
                ++length;
                up = 1;
            }
        }

        return length;
    }
};
