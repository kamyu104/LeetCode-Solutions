# Time:  O(n)
# Space: O(n)

import collections


# mono deque, two pointers, sliding window, dp, prefix sum
class Solution(object):
    def countPartitions(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        max_dq, min_dq = collections.deque(), collections.deque()
        dp = [0]*(len(nums)+1)
        dp[0] = 1
        left = suffix = 0
        for right in xrange(len(nums)):
            suffix = (suffix+dp[right])%MOD
            while max_dq and nums[max_dq[-1]] <= nums[right]:
                max_dq.pop()
            max_dq.append(right)
            while min_dq and nums[min_dq[-1]] >= nums[right]:
                min_dq.pop()
            min_dq.append(right)
            while nums[max_dq[0]]-nums[min_dq[0]] > k:
                if min_dq[0] == left:
                    min_dq.popleft()
                if max_dq[0] == left:
                    max_dq.popleft()
                suffix = (suffix-dp[left])%MOD
                left += 1
            dp[right+1] = suffix
        return dp[-1]
