// Time:  O(n)
// Space: O(min(n, k))

// prefix sum, freq table
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int64_t result = 0, prefix = 0;
        for (int64_t i = 0, prefix = 0; i < size(nums);) {
            int j = i, prefix2 = prefix;
            for (; j < size(nums) && nums[j] == nums[i]; ++j) {
                prefix2 = (prefix2 + nums[j]) % k;
                result += cnt[prefix2];
            }
            for (; i < j; ++i) {
                prefix = (prefix + nums[i]) % k;
                ++cnt[prefix];
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(min(n, k))
// prefix sum, freq table
class Solution2 {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int64_t result = 0, prefix = 0;
        for (const auto& x : nums) {
            prefix = (prefix + x) % k;
            result += cnt[prefix];
            ++cnt[prefix];
        }
        for (int i = 0, l = 0; i < size(nums); ++i) {
            ++l;
            if (i + 1 == size(nums) || nums[i + 1] != nums[i]) {
                for (int64_t j = 1; j <= l; ++j) {
                    if (nums[i] * j % k == 0) {
                        result -= (l - j + 1) - 1;
                    }
                }
                l = 0;
            }
        }
        return result;
    }
};
