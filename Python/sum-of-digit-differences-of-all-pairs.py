# Time:  O(nlogr)
# Space: O(10 * logr)

# prefix sum
class Solution(object):
    def sumDigitDifferences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        base, l = 1, 0
        while base <= nums[0]:
            base *= 10
            l += 1
        cnts = [[0]*10 for _ in xrange(l)]
        for x in nums:
            for i in xrange(l):
                cnts[i][x%10] += 1
                x //= 10
        return sum(c*(len(nums)-c) for cnt in cnts for c in cnt)//2
