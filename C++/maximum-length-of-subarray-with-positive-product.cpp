// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int result = 0, neg_cnt = 0, last_zero_idx = -1, first_valid_neg_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                neg_cnt = 0;
                last_zero_idx = i;
                first_valid_neg_idx = -1;
                continue;
            }
            if (nums[i] < 0) {
                if (first_valid_neg_idx == -1) {
                    first_valid_neg_idx = i;
                }
                ++neg_cnt;
            } 
            result = max(result, i - ((neg_cnt % 2 == 0) ? last_zero_idx : first_valid_neg_idx));
        }
        return result;
    }
};
