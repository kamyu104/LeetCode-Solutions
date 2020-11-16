// Time:  O(n * 4^m) 
// Space: O(2^m)

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> count;
        for(int i = 0; i < size(nums); ++i) {
            ++count[nums[i]];
        }
        int total = (1 << size(quantity)) - 1;
        vector<int> requirement(total + 1);
        for (int mask = 0; mask < size(requirement); ++mask) {  // Time: O(2^m)
            for (int i = 0; i < size(quantity); ++i) {  // Time: O(m)
                if (mask & (1 << i)) {
                    requirement[mask] += quantity[i];
                }
            }
        }
        vector<vector<int>> dp(2, vector<int>(total + 1));
        dp[0][0] = 1;
        int i = 0;
        for (const auto& [num, cnt] : count) {  // Time: O(n)
            dp[(i + 1) % 2] = vector<int>(total + 1);
            for (int mask = total; mask >= 0; --mask) {  // Time: O(2^m)
                dp[(i + 1) % 2][mask] |= dp[i % 2][mask];
                for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {  // Time: O(2^m)
                    if (requirement[subMask] <= cnt && dp[i % 2][mask ^ subMask]) {
                        dp[(i + 1) % 2][mask] = 1;
                    }
                }
            }
            ++i;
        }
        return dp[size(count) % 2][total];
    }
};
