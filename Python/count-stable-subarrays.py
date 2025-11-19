# Time:  O(n + q)
# Space: O(n)

# prefix sum
class Solution(object):
    def countStableSubarrays(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def count(n):
            return (n+1)*n//2

        right = range(len(nums))
        for i in reversed(xrange(len(nums)-1)):
            if nums[i] <= nums[i+1]:
                right[i] = right[i+1]
        prefix = [0]*(len(nums)+1)
        curr = 0
        for i in xrange(len(nums)):
            if i-1 >= 0 and nums[i-1] > nums[i]:
                curr = 0
            curr += 1
            prefix[i+1] = prefix[i]+curr
        return [count(min(right[l], r)-l+1)+(prefix[r+1]-prefix[min(right[l], r)+1]) for l, r in queries]
