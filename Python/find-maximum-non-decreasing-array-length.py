# Time:  O(n)
# Space: O(n)

# greedy, prefix sum, mono stack, two pointers
class Solution(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = prefix = left = 0
        stk = [(0, 0, 0)]
        for right in xrange(len(nums)):
            prefix += nums[right]
            while left+1 < len(stk) and stk[left+1][0] <= prefix:
                left += 1
            last, dp = prefix-stk[left][1], stk[left][2]+1
            while stk and stk[-1][0] >= last+prefix:
                stk.pop()
            stk.append((last+prefix, prefix, dp))
            left = min(left, len(stk)-1)
        return dp


# Time:  O(nlogn)
# Space: O(n)
import bisect


# greedy, prefix sum, mono stack, binary search
class Solution2(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = prefix = left = 0
        stk = [(0, 0, 0)]
        for right in xrange(len(nums)):
            prefix += nums[right]
            left = bisect.bisect_left(stk, (prefix+1, 0, 0))-1
            last, dp = prefix-stk[left][1], stk[left][2]+1
            while stk and stk[-1][0] >= last+prefix:
                stk.pop()
            stk.append((last+prefix, prefix, dp))
        return dp
