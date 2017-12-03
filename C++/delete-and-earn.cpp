// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vals(10001);
        for (const auto& num : nums) {
            vals[num] += num;
        }
        int val_i = vals[0], val_i_1 = 0, val_i_2 = 0;
        for (int i = 1; i < vals.size(); ++i) {
            val_i_2 = val_i_1;
            val_i_1 = val_i;
            val_i = max(vals[i] + val_i_2, val_i_1);
        }
        return val_i;
    }
};
