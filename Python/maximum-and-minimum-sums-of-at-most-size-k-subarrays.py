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
                while dq and not check(nums[dq[-1]], nums[right]):
                    i = dq.pop()
                    cnt = i-(dq[-1]+1 if dq else max(right-k+1, 0))+1
                    total -= cnt*nums[i]
                cnt = right-(dq[-1]+1 if dq else max(right-k+1, 0))+1
                dq.append(right)
                total += cnt*nums[right]
                result += total
                if right-(k-1) >= 0:
                    total -= nums[dq[0]]
                    if dq[0] == right-(k-1):
                        dq.popleft()
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
                left = right
                while dq and not check(nums[dq[-1][0]], nums[right]):
                    i, left = dq.pop()
                    total -= (i-left+1)*nums[i]
                dq.append([right, left])
                total += (right-left+1)*nums[right]
                result += total
                if right-(k-1) >= 0:
                    total -= nums[dq[0][0]]
                    if dq[0][0] == right-(k-1):
                        dq.popleft()
                    else:
                        assert(dq[0][1] == right-(k-1))
                        dq[0][1] += 1
            return result
    
        return count(lambda a, b: a < b)+count(lambda a, b: a > b)
