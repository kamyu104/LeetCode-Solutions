// Time:  O(n + rlogr), r = max(nums)
// Space: O(r)

// number theory
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        const auto& mx = ranges::max(nums);        
        vector<int> lookup(mx + 1);
        for (const auto& x : nums) {
            lookup[x] = x;
        }
        for (int i = 1; i <= mx; ++i) {
            if (!lookup[i]) {
                continue;
            }
            for (int j = i + i; j <= mx; j += i) {
                if (lookup[j] == j) {
                    lookup[j] = i;
                }
            }
        }
        int64_t result = 0;
        for (const auto& x : nums) {
            result += lookup[x];
        }
        return result;
    }
};
