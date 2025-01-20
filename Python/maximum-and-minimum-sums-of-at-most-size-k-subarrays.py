# Time:  O(n)
# Space: O(k)

import collections


# two pointers, sliding window, mono deque
class Solution(object):
    def minMaxSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def count(check):
            result = total = 0
            dq = collections.deque()
            for right in xrange(len(nums)):
                while dq and dq[0][0] <= right-k:
                    total -= nums[dq.popleft()[0]]
                if dq and dq[0][1] == right-k:
                    total -= nums[dq[0][0]]
                    dq[0][1] += 1
                left = right
                while dq and not check(nums[dq[-1][0]], nums[right]):
                    total -= (dq[-1][0]-dq[-1][1]+1)*nums[dq[-1][0]]
                    left = dq.pop()[1]
                dq.append([right, left])
                total += (right-left+1)*nums[right]
                result += total
            return result
    
        return count(lambda a, b: a < b)+count(lambda a, b: a > b)
