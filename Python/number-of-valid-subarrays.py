# Time:  O(n)
# Space: O(n)

class Solution(object):
    def validSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        s = []
        for num in nums:
            while s and s[-1] > num:
                s.pop()
            s.append(num);
            result += len(s)
        return result
