# Time:  O(logn)
# Space: O(1)

# A peak element is an element that is greater than its neighbors.
# 
# Given an input array where num[i] != num[i+1],
# find a peak element and return its index.
# 
# The array may contain multiple peaks, in that case 
# return the index to any one of the peaks is fine.
# 
# You may imagine that num[-1] = num[n] = -infinite.
# 
# For example, in array [1, 2, 3, 1], 3 is a peak element
# and your function should return the index number 2.
#
# Note:
# Your solution should be in logarithmic complexity.


class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = left + (right - left) / 2
            if (mid == 0 or nums[mid - 1] < nums[mid]) and \
               (mid + 1 == len(nums) or nums[mid] > nums[mid + 1]):
                return mid
            elif not (mid == 0 or nums[mid - 1] < nums[mid]):
                right = mid
            else:
                left = mid + 1
       
        return left


if __name__ == "__main__":
   # print Solution().findPeakElement([1,2,1])
    print Solution().findPeakElement([1,2,3,1])
