# Time:  O(nlogn)
# Space: O(n)

# heap
class Solution(object):
    def maximumScore(self, nums, s):
        """
        :type nums: List[int]
        :type s: str
        :rtype: int
        """
        result = 0
        max_heap = []
        for i in xrange(len(nums)):
            heapq.heappush(max_heap, -nums[i])
            if s[i] == '1':
                result += -heapq.heappop(max_heap)
        return result
