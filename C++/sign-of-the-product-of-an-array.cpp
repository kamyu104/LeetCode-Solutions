// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        uint8_t flag = 0;
        for (const auto& x : nums) {
            if (x == 0) {
                return 0;
            }
            if (x < 0) {
                flag ^= 1;
            }
        }
        return flag % 2 ? -1 : 1;
    }
};
