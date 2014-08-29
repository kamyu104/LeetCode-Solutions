# Time: O(n^2)
# Space: O(1)
#
# Given an array S of n integers, 
# find three integers in S such that the sum is closest to a given number, target. 
# Return the sum of the three integers. 
# You may assume that each input would have exactly one solution.
#
# For example, given array S = {-1 2 1 -4}, and target = 1.
#
# The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution:
    # @return an integer
    def threeSumClosest(self, nums, target):
        nums, result, min_diff, i = sorted(nums), 2147483647, 2147483647, 0
        while i < len(nums) - 2:
            j, k = i + 1, len(nums) - 1
            while j < k:
                diff = nums[i] + nums[j] + nums[k] - target
                if abs(diff) < min_diff:
                    min_diff = abs(diff)
                    result = nums[i] + nums[j] + nums[k]
                if diff < 0:
                    j += 1
                elif diff > 0:
                    k -= 1
                else:
                    return target
            i += 1
            while i < len(nums) - 2 and nums[i] == nums[i - 1]:
                i += 1
        return result

if __name__ == '__main__':
    result = Solution().threeSumClosest([-1, 2, 1, -4], 1)
    print result