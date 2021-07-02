# Time:  O(nlogr)
# Space: O(1)

class Solution(object):
    def kthSmallestSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def check(nums, k, x):
            cnt = curr = left = 0
            for right in xrange(len(nums)):
                curr += nums[right]
                while curr > x:
                    curr -= nums[left]
                    left += 1
                cnt += right-left+1
            return cnt >= k

        left, right = min(nums), sum(nums)
        while left <= right:
            mid = left + (right-left)//2
            if check(nums, k, mid):
                right = mid-1
            else:
                left = mid+1
        return left
