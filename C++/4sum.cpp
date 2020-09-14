// Time:  O(n^3)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = 0; i + 3 < size(nums); ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j + 2 < size(nums); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                const auto& total = target - nums[i] - nums[j];
                int left = j + 1, right = size(nums) - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == total) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > total) {
                            --right;
                        } else {
                            ++left;
                        }
                    }
                }
            }
        }
        return result;
    }
};
