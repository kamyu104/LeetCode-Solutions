# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maxDistinctElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        nums.sort()
        curr = float("-inf")
        for x in nums:
            if curr > x+k:
                continue
            curr = max(curr, x-k)+1
            result += 1
        return result
