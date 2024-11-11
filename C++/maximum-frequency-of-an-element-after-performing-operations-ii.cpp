// Time:  O(nlogn)
// Space: O(n)

// sort, freq table, two pointers, sliding window
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(begin(nums), end(nums));
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0, left = 0, right = -1; i < size(nums); ++i) {
            while (right + 1 < size(nums) && nums[right + 1] - nums[i] <= k) {
                ++cnt[nums[++right]];
            }
            while (nums[i] - nums[left] > k) {
                --cnt[nums[left++]];
            }
            result = max(result, cnt[nums[i]] + min((right - left + 1) - cnt[nums[i]], numOperations));
        }
        for (int right = 0, left = 0; right < size(nums); ++right) {
            while (nums[left] + k < nums[right] - k) {
                ++left;
            }
            result = max(result, min(right - left + 1, numOperations));
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, freq table, difference array, line sweep
class Solution2 {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        map<int, int> diff;
        for (const auto& x : nums) {
            diff[x] += 0;
            ++diff[x - k];
            --diff[x + k + 1];
        }
        int result = 0, curr = 0;
        for (const auto& [x, c] : diff) {
            curr += c;
            result = max(result, cnt[x] + min(curr - cnt[x], numOperations));
        }
        return result;
    }
};
