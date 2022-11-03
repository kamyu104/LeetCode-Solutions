# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def averageValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = cnt = 0
        for x in nums:
            if x%6:
                continue
            total += x
            cnt += 1
        return total//cnt if cnt else 0
