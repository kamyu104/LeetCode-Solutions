// Time:  O(n^2 * logr)
// Space: O(1)

// brute force, pruning
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                if (static_cast<int64_t>(nums[i]) * nums[j] <= result) {
                    break;
                }
                const int64_t g = gcd(nums[i], nums[j]);
                result = max(result, (nums[i] / g) * (nums[j] / g));
            }
        }
        return result;
    }
};

// Time:  O(n^2 * logr)
// Space: O(1)
// brute force
class Solution2 {
public:
    long long maxPairStrength(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                const int64_t g = gcd(nums[i], nums[j]);
                result = max(result, (nums[i] / g) * (nums[j] / g));
            }
        }
        return result;
    }
};
