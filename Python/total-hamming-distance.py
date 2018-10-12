# Time:  O(n)
# Space: O(1)

class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(32):
            counts = [0] * 2
            for num in nums:
                counts[(num >> i) & 1] += 1
            result += counts[0] * counts[1]
        return result


