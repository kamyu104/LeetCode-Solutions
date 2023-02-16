// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const auto& count = [&](int64_t x) {
            int64_t cnt = 0;
            int left = 0, right = size(nums) - 1;
            while (left < right) {
                if (nums[left] + nums[right] <= x) {
                    cnt += right - left++;
                } else {
                    --right;
                }
            }
            return cnt;
        };

        sort(begin(nums), end(nums));
        return count(upper) - count(lower - 1);
    }
};
