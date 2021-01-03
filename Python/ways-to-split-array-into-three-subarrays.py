# Time:  O(n)
# Space: O(n)

class Solution(object):
    def waysToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7

        prefix = [0]
        for x in nums:
            prefix.append(prefix[-1]+x)

        result = left = right = 0 
        for i in xrange(len(nums)): 
            left = max(left, i+1)
            while left+1 < len(nums) and prefix[i+1] > prefix[left+1]-prefix[i+1]:
                left += 1
            right = max(right, left)
            while right+1 < len(nums) and prefix[right+1]-prefix[i+1] <= prefix[-1]-prefix[right+1]:
                right += 1
            result = (result + (right-left))%MOD
        return result
