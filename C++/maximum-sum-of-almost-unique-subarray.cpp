// Time:  O(n)
// Space: O(n)

// freq table, two pointers, sliding window
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> lookup;
        long long result = 0, curr = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            curr += nums[right];
            ++lookup[nums[right]];
            if (right - left + 1 == k + 1) {
                if (--lookup[nums[left]] == 0) {
                    lookup.erase(nums[left]);
                }
                curr -= nums[left];
                ++left;
            }
            if (right - left + 1 == k && size(lookup) >= m) {
                result = max(result, curr);
            }
        }
        return result;
    }
};
