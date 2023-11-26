# Time:  O(n)
# Space: O(n)

# dp, greedy, prefix sum, mono stack, two pointers
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


# Time:  O(n)
# Space: O(n)
import collections


# greedy, prefix sum, mono deque
class Solution2(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = prefix = prev_prefix = prev_dp = 0
        dq = collections.deque()
        for right in xrange(len(nums)):
            prefix += nums[right]
            while dq and dq[0][0] <= prefix:
                _, prev_prefix, prev_dp = dq.popleft()
            last, dp = prefix-prev_prefix, prev_dp+1
            while dq and dq[-1][0] >= last+prefix:
                dq.pop()
            dq.append((last+prefix, prefix, dp))
        return dp


# Time:  O(nlogn)
# Space: O(n)
import bisect


# dp, greedy, prefix sum, mono stack, binary search
class Solution3(object):
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


# Time:  O(nlogn)
# Space: O(n)
import bisect


# dp, greedy, prefix sum, binary search
class Solution4(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        dp = [float("inf")]*(len(nums)+1)
        dp[0] = 0
        prev = [-1]*(len(nums)+1)
        left = -1
        for right in xrange(len(nums)):
            left = max(left, prev[right])
            dp[right+1] = dp[left+1]+1
            next_right = bisect.bisect_left(prefix, prefix[right+1]+(prefix[right+1]-prefix[left+1]))-1
            prev[next_right] = right
        return dp[-1]
