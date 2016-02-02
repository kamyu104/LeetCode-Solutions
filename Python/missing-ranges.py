# Time:  O(n)
# Space: O(1)
#
# Given a sorted integer array where the range of elements are [lower, upper] inclusive,
# return its missing ranges.
# 
# For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, 
# return ["2", "4->49", "51->74", "76->99"].
#

class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        def getRange(lower, upper):
            if lower == upper:
                return "{}".format(lower)
            else:
                return "{}->{}".format(lower, upper)
        ranges = []
        pre = lower - 1
        
        for i in xrange(len(nums) + 1):
            if i == len(nums):
                cur = upper + 1
            else:
                cur = nums[i]
            if cur - pre >= 2:
                ranges.append(getRange(pre + 1, cur - 1))
                
            pre = cur
            
        return ranges


if __name__ == "__main__":
    print Solution().findMissingRanges([0, 1, 3, 50, 75], 0, 99)
