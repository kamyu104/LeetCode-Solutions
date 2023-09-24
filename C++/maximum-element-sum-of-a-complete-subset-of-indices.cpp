// Time:  O(n * (1 + 1/4 + 1/9 + ...)) = O(pi^2 * 6 * n) = O(n), see https://en.wikipedia.org/wiki/Basel_problem
// Space: O(1)

// number theory, basel problem
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int64_t result = 0;
        for (int i = 1; i <= size(nums); ++i) {
            int64_t curr = 0;
            for (int x = 1; i * x * x - 1 < size(nums); ++x) {
                curr += nums[i * x * x - 1];
            }
            result = max(result, curr);
        }
        return result;
    }
};
