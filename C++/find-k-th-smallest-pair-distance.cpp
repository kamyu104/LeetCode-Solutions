// Time:  O(nlogn + nlogw), n = len(nums), w = max(nums) - min(nums)
// Space: O(1)

// Binary search with sliding window solution
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front() + 1;
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (possible(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool possible(const int guess, const vector<int>& nums, const int k) {
        int count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while ((nums[right] - nums[left]) > guess) {
                ++left;
            }
            count += right - left;
        }
        return count >= k;
    }
};
