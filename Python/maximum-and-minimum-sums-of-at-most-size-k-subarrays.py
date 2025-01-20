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
                if right-k >= 0:
                    total -= nums[dq[0]]
                    if dq[0] == right-k:
                        dq.popleft()
                while dq and not check(nums[dq[-1]], nums[right]):
                    i = dq.pop()
                    cnt = i-(dq[-1]+1 if dq else max(right-k+1, 0))+1
                    total -= cnt*nums[i]
                cnt = right-(dq[-1]+1 if dq else max(right-k+1, 0))+1
                dq.append(right)
                total += cnt*nums[right]
                result += total
            return result
    
        return count(lambda a, b: a < b)+count(lambda a, b: a > b)


# Time:  O(n)
# Space: O(k)
import collections


# two pointers, sliding window, mono deque
class Solution2(object):
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
                if dq:
                    if dq[0][0] == right-k:
                        total -= nums[dq.popleft()[0]]
                    elif dq[0][1] == right-k:
                        total -= nums[dq[0][0]]
                        dq[0][1] += 1
                left = right
                while dq and not check(nums[dq[-1][0]], nums[right]):
                    i, left = dq.pop()
                    total -= (i-left+1)*nums[i]
                dq.append([right, left])
                total += (right-left+1)*nums[right]
                result += total
            return result
    
        return count(lambda a, b: a < b)+count(lambda a, b: a > b)
