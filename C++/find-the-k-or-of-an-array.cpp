// Time:  O(nlogr)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0; 
        const int mx = *max_element(cbegin(nums), cend(nums));
        const int l = mx != 0 ? __lg(mx) : -1;
        for (int i = 0; i <= l; ++i) {
            int cnt = 0;
            for (const auto& x : nums) {
                if ((x & (1 << i)) == 0) {
                    continue;
                }
                if (++cnt == k) {
                    result += 1 << i;
                    break;
                }
            }
        }
        return result;
    }
};
