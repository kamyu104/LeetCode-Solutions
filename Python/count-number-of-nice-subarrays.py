# Time:  O(n)
# Space: O(k)

class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def atMost(nums, k):
            result, left, count = 0, 0, 0
            for right, x in enumerate(nums):
                count += x%2
                while count > k:
                    count -= nums[left]%2
                    left += 1
                result += right-left+1
            return result

        return atMost(nums, k) - atMost(nums, k-1)


# Time:  O(n)
# Space: O(k)
import collections


class Solution2(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        dq = collections.deque([-1])
        for i in xrange(len(nums)):
            if nums[i]%2:
                dq.append(i)
            if len(dq) > k+1:
                dq.popleft()
            if len(dq) == k+1:
                result += dq[1]-dq[0]
        return result
