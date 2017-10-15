// Time:  O(k^n)
// Space: O(n)

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> subset_sums(k);
        return dfs(nums, sum / k, 0, &subset_sums);
    }

private:
    bool dfs(const vector<int> &nums, const int target,
             const int i, vector<int> *subset_sums) {
        if (i == nums.size()) {
            return true;
        }
        for (auto& subset_sum : *subset_sums) {
            if (subset_sum + nums[i] > target) {
                continue;
            }
            subset_sum += nums[i];
            if (dfs(nums, target, i + 1, subset_sums)) {
                return true;
            }
            subset_sum -= nums[i];
        }
        return false;
    }
};
