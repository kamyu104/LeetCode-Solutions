# Time:  O(nlogn)
# Space: O(n)

import heapq


# greedy, heap
class Solution(object):
    def convertArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def f(nums):
            result = 0
            max_heap = []
            for x in nums:
                if max_heap and x < -max_heap[0]:
                    result += -heapq.heappop(max_heap)-x
                    heapq.heappush(max_heap, -x)
                heapq.heappush(max_heap, -x)
            return result
        
        return min(f(nums), f((x for x in reversed(nums))))


# Time:  O(n^2)
# Space: O(n)
import collections


# dp
class Solution2(object):
    def convertArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        vals = sorted(set(nums))
        def f(nums):
            dp = collections.defaultdict(int)  # dp[i]: min(cnt(j) for j in vals if j <= i)
            for x in nums:
                prefix = float("inf")
                for i in vals:
                    prefix = min(prefix, dp[i]+abs(i-x))
                    dp[i] = prefix
            return dp[vals[-1]]

        return min(f(nums), f((x for x in reversed(nums))))
