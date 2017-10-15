// Time:  O(n*2^n)
// Space: O(2^n)

// DP solution.
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || *max_element(nums.begin(), nums.end()) > sum / k) {
            return false;
        }
        unordered_map<int, int> lookup;
        lookup[(1 << nums.size()) - 1] = true;
        return dfs(nums, sum / k, 0, sum, &lookup);
    }

private:
    bool dfs(const vector<int>& nums, const int target,
             const int used, const int todo,
             unordered_map<int, int> *lookup) {
        if (!lookup->count(used)) {
            const auto targ = (todo - 1) % target + 1;
            for (int i = 0; i < nums.size(); ++i) {
                if (((used >> i) & 1) == 0 && nums[i] <= targ) {
                    if (dfs(nums, target, used | (1 << i), todo - nums[i], lookup)) {
                        (*lookup)[used] = true;
                        break;
                    }
                }
            }
        }
        return (*lookup)[used];
    }
};

// Time:  O(k^(n-k) * k!)
// Space: O(n)
// DFS solution with pruning.
class Solution2 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || *max_element(nums.begin(), nums.end()) > sum / k) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());  // speedup dfs
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
            if (subset_sum == 0) {  // pruning
                break;
            }
        }
        return false;
    }
};
