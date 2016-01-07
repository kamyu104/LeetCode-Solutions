// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int ans = numeric_limits<int>::max();
        int min_diff = numeric_limits<int>::max();

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                int j = i + 1;
                int k = nums.size() - 1;
    
                while (j < k) {  // Time: O(n) for each i.
                    const auto sum = nums[i] + nums[j] + nums[k];
    
                    if (sum > target) {  // Should decrease sum.
                        --k;
                    } else if (sum < target) {  // Should increase sum.
                        ++j;
                    } else {
                        return target;
                    }
    
                    if (abs(sum - target) < min_diff) {
                        min_diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};
