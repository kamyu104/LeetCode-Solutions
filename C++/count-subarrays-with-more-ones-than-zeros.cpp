// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int> lookup(2 * size(nums) + 1);
        lookup[0 + size(nums)] = 1;
        int result = 0, total = 0, same = 0, more = 0;
        for (const auto& num : nums) {
            total += (num == 1) ? 1 : -1;
            const int new_same = lookup[total + size(nums)];
            const int new_more = (num == 1) ? (same + more + 1) % MOD : (more - new_same + MOD) % MOD;
            ++lookup[total + size(nums)];
            result = (result + new_more) % MOD;
            same = new_same, more = new_more;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int> lookup(2 * size(nums) + 1, -2);
        lookup[0 + size(nums)] = -1;
        vector<int> dp(size(nums));
        int result = 0, total = 0;
        for (int i = 0; i < size(nums); ++i) {
            total += (nums[i] == 1) ? 1 : -1;
            if (lookup[total + size(nums)] == -2) {
                if (total > 0) {
                    dp[i] = i + 1;
                }
            } else {
                const int j = lookup[total + size(nums)];
                dp[i] = (j == -1) ? 0 : dp[j];
                if (nums[i] > 0) {
                    dp[i] += (i - 1) - j;
                } 
            }
            lookup[total + size(nums)] = i;
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};
