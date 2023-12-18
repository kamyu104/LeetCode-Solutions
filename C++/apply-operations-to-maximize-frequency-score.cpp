// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers, sliding window
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));
        int64_t curr = 0;
        int right = 0, left = 0;
        for (; right < size(nums); ++right) {
            curr += nums[right] - nums[(left + right) / 2];
            if (!(curr <= k)) {
                curr -= nums[((left + 1) + right) / 2] - nums[left++];
            }
        }
        return right - left;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, two pointers, sliding window
class Solution2 {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));
        int result = 0;
        int64_t curr = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            curr += nums[right] - nums[(left + right) / 2];
            while (!(curr <= k)) {
                curr -= nums[((left + 1) + right) / 2] - nums[left++];
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
