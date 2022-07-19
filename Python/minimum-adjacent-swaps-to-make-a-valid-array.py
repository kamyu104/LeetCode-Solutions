# Time:  O(n)
# Space: O(1)

# array, greedy
class Solution(object):
    def minimumSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_idx = min(xrange(len(nums)), key=nums.__getitem__)
        max_idx = max(reversed(xrange(len(nums))), key=nums.__getitem__)
        return ((len(nums)-1)-max_idx)+min_idx-int(max_idx < min_idx)
