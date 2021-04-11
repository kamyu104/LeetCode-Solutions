# Time:  O(n)
# Space: O(1)

class Solution(object):
    def arraySign(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        flag = 0
        for x in nums:
            if not x:
                return 0
            if x < 0:
                flag ^= 1
        return -1 if flag else 1
