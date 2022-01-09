# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt = w = nums.count(1)
        for i in xrange(len(nums)+(w-1)):
            if i >= w:
                cnt += nums[(i-w)%len(nums)]
            cnt -= nums[i%len(nums)]
            result = min(result, cnt)
        return result
