// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int mx = *max_element(cbegin(nums), cend(nums));
        int64_t result = 0;
        for (int right = 0, left = 0, cnt = 0; right < size(nums); ++right) {
            cnt += static_cast<int>(nums[right] == mx);
            while (cnt == k) {
                cnt -= static_cast<int>(nums[left++] == mx);
            }
            result += left;
        }
        return result;
    }
};
