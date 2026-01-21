// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        static const int MOD = 1e9 + 7;

        vector<int> vals = {0, target1, target1 ^ target2, target2};
        vector<int> dp(size(vals));
        dp[0] = 1;
        int prefix = 0;
        for (int i = 0; i + 1 < size(nums); ++i) {
            vector<int> new_dp(dp);
            prefix ^= nums[i];
            for (int j = 0; j < size(vals); ++j) {
                if (vals[j] != prefix) {
                    continue;
                }
                new_dp[j] = (new_dp[j] + dp[((j - 1) % size(dp) + size(dp)) % size(dp)]) % MOD;
            }
            dp = move(new_dp);
        }
        prefix ^= nums.back();
        int result = 0;
        for (int j = 0; j < size(vals); ++j) {
            if (vals[j] != prefix) {
                continue;
            }
            result = (result + dp[((j - 1) % size(dp) + size(dp)) % size(dp)]) % MOD;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> cnt1, cnt2;
        cnt2[0] = 1;
        int c1 = 0, c2 = 0;
        for (int i = 0, prefix = 0; i < size(nums); ++i) {
            prefix ^= nums[i];
            c1 = cnt2[prefix ^ target1];
            c2 = cnt1[prefix ^ target2];
            cnt1[prefix] = (cnt1[prefix] + c1) % MOD;
            cnt2[prefix] = (cnt2[prefix] + c2) % MOD;
        }
        return (c1 + c2) % MOD;
    }
};
