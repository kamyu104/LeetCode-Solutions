from __future__ import print_function
# Time:  O(n)
# Space: O(1)

class Solution:
    def twoSum(self, nums, target):
        start, end = 0, len(nums) - 1

        while start != end:
            sum = nums[start] + nums[end]
            if sum > target:
                end -= 1
            elif sum < target:
                start += 1
            else:
                return [start + 1, end + 1]

if __name__ == "__main__":
    print(Solution().twoSum([2, 7, 11, 15], 9))

