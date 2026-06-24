// Time:  O(nlogr)
// Space: O(n)

// prefix sum, two pointers
class Solution {
public:
    long long countValidSubarrays(vector<int>& nums, int x) {
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int64_t result = 0;
        for (int64_t base = 1; x * base <= prefix.back(); base *= 10) {
            vector<int64_t> cnt(10);
            for (int r = 0, left = 0, right = 0; r < size(nums); ++r) {
                while (prefix[right] <= prefix[r + 1] - x * base) {
                    ++cnt[prefix[right] % 10];
                    ++right;
                }
                while (prefix[left] <= prefix[r + 1] - (x + 1) * base) {
                    --cnt[prefix[left] % 10];
                    ++left;
                }
                result += cnt[((prefix[r + 1] - x) % 10 + 10) % 10];
            }
        }
        return result;
    }
};
