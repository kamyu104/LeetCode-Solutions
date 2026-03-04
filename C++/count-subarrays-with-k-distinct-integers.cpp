// Time:  O(n)
// Space: O(n)

// freq table, two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        unordered_map<int, int> cnt1, cnt2;
        int64_t result = 0;
        int left = 0, right = 0, l = 0;
        for (const auto& x : nums) {
            ++cnt1[x];
            for (; size(cnt1) == k + 1; ++left) {
                --cnt1[nums[left]];
                if (cnt1[nums[left]] == 0) {
                    cnt1.erase(nums[left]);
                }
            }
            ++cnt2[x];
            if (cnt2[x] == m) {
                ++l;
            }
            for (; l == k; ++right) {
                if (cnt2[nums[right]] == m) {
                    --l;
                }
                --cnt2[nums[right]];
                if (cnt2[nums[right]] == 0) {
                    cnt2.erase(nums[right]);
                }
            }
            result += max(right - left, 0);
        }
        return result;
    }
};
