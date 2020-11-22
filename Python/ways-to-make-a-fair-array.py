# Time:  O(n)
# Space: O(1)

class Solution(object):
    def waysToMakeFair(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = [0]*2
        suffix = [sum(nums[i] for i in xrange(k, len(nums), 2)) for k in xrange(2)]
        result = 0
        for i, num in enumerate(nums):
            suffix[i%2] -= num
            result += int(prefix[0]+suffix[1] == prefix[1]+suffix[0])
            prefix[i%2] += num
        return result
