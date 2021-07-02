// Time:  O(nlogr)
// Space: O(1)

class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int left = *min_element(cbegin(nums), cend(nums));
        int right = accumulate(cbegin(nums), cend(nums), 0);
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(nums, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<int>& nums, int k, int x) {
        int cnt = 0, curr = 0, left = 0;
        for (int right = 0; right < size(nums); ++right) {
            curr += nums[right];
            while (curr > x) {
                curr -= nums[left++];
            }
            cnt += right - left + 1;
        }
        return cnt >= k;
    }
};
