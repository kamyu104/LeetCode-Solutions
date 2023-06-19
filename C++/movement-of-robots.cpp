// Time:  O(nlogn)
// Space: O(1)

// sort, math
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        static const int MOD = 1e9 + 7;

        for (int i = 0; i < size(nums); ++i) {
            nums[i] += s[i] == 'R' ? d : -d;
        }
        sort(begin(nums), end(nums));
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result = ((result + static_cast<int64_t>(i - (size(nums) - (i + 1))) * nums[i]) % MOD + MOD) % MOD;
        }
        return result;
    }
};
