# Time:  O(n)
# Space: O(n)

# greedy, prefix sum
class Solution(object):
    def minCost(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [0]*((len(nums)-1)+1)
        for i in xrange(len(prefix)-1):
            prefix[i+1] = prefix[i]+(1 if i-1 == -1 or nums[i+1]-nums[i] < nums[i]-nums[i-1] else nums[i+1]-nums[i])
        suffix = [0]*((len(nums)-1)+1)
        for i in reversed(xrange(1, len(suffix))):
            suffix[i-1] = suffix[i]+(1 if i+1 == len(nums) or nums[i]-nums[i-1] <= nums[i+1]-nums[i] else nums[i]-nums[i-1])
        return [prefix[right]-prefix[left] if left < right else suffix[right]-suffix[left] for left, right in queries]
