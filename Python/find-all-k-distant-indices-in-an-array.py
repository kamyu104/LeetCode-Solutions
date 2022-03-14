# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def findKDistantIndices(self, nums, key, k):
        """
        :type nums: List[int]
        :type key: int
        :type k: int
        :rtype: List[int]
        """
        result = []
        prev = -1
        for i, x in enumerate(nums):
            if x != key:
                continue
            for j in xrange(max(i-k, prev+1), min(i+k+1, len(nums))):
                result.append(j)
            prev = min(i+k, len(nums)-1)
        return result
