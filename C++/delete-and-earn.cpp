// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> values(10001);
        for (const auto& num : nums) {
            values[num] += num;
        }
        int val_i = values[0], val_i_1 = 0, val_i_2 = 0;
        for (int i = 1; i < values.size(); ++i) {
            val_i_2 = val_i_1;
            val_i_1 = val_i;
            val_i = max(values[i] + val_i_2, val_i_1);
        }
        return val_i;
    }
};
