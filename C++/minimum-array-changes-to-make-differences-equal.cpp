// Time:  O(n + k)
// Space: O(k)

// prefix sum, difference array
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> diff((k + 1) + 1);
        const auto& update = [&](int left, int right, int d) {
            diff[left] += d;
            diff[right + 1] -= d;
        };
        
        for (int i = 0; i < size(nums) / 2; ++i) {
            const int curr = abs(nums[i] - nums[size(nums) - 1 - i]);
            const int mx = max({nums[i] - 0, k - nums[i], nums[size(nums) - 1 - i] - 0, k - nums[size(nums) - 1 - i]});
            // 1 change for i in range(0, curr)
            update(0, curr - 1, 1);
            // 1 change for i in range(curr+1, mx+1)
            update(curr + 1, mx, 1);
            // 2 changes for i in range(mx+1, k+1)
            update(mx + 1, k, 2);
        }
        int result = size(nums) / 2;
        for (int i = 0, curr = 0; i <= k; ++i) {
            curr += diff[i];
            result = min(result, curr);
        }
        return result;
    }
};
