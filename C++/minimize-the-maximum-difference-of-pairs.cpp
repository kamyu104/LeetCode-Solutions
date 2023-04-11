// Time:  O(nlogn + nlogr), r = max(nums)-min(nums)
// Space: O(1)

// sort, binary search, greedy
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        const auto& check = [&](int x) {
            int cnt = 0;
            for (int i = 0; i + 1 < size(nums) && cnt < p; ++i) {
                if (nums[i + 1] - nums[i] <= x) {
                    ++i;
                    ++cnt;
                }
            }
            return cnt == p;
        };

        sort(begin(nums), end(nums));
        int left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
