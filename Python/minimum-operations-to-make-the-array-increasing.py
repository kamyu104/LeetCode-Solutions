# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = prev = 0
        for curr in nums:
            if prev < curr:
                prev = curr
                continue
            prev += 1
            result += prev-curr                
        return result
