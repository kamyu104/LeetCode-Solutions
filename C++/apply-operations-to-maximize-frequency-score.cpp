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

// Time:  O(nlogn)
// Space: O(n)
// sort, prefix sum, binary search
class Solution3 {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        const auto& check = [&](int l) {
            for (int i = 0; i < size(nums) - l + 1; ++i) {
                if ((prefix[i + l] - prefix[i + (l + 1) / 2]) - (prefix[i + l / 2] - prefix[i]) <= k) {
                    return true;
                }
            }
            return false;
        };

        int left = 1, right = size(nums);
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
