# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse=True)
        curr = 0
        for i, x in enumerate(nums):
            curr += x
            if curr <= 0:
                return i
        return len(nums)
