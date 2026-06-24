// Time:  O(nlogr)
// Space: O(n)

// prefix sum, two pointers
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int result = 0;
        for (int64_t base = 1; x * base <= prefix.back(); base *= 10) {
            vector<int64_t> cnt(10);
            for (int i = 0, left = 0, right = 0; i < size(nums); ++i) {
                for (; prefix[right] <= prefix[i + 1] - x * base; ++right) {
                    ++cnt[prefix[right] % 10];
                }
                for (; prefix[left] <= prefix[i + 1] - (x + 1) * base; ++left) {
                    --cnt[prefix[left] % 10];
                }
                result += cnt[((prefix[i + 1] - x) % 10 + 10) % 10];
            }
        }
        return result;
    }
};

// Time:  O(n^2 * logr)
// Space: O(n)
// brute force
class Solution2 {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        const auto& check = [&](auto n) {
            if (n % 10 != x) {
                return false;
            }
            for (; n / 10; n /= 10);
            return n == x;
        };

        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            int64_t total = 0;
            for (int j = i; j < size(nums); ++j) {
                total += nums[j];
                if (check(total)) {
                    ++result;
                }
            } 
        }
        return result;
    }
};
