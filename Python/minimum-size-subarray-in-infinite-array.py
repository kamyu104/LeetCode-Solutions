# Time:  O(n)
# Space: O(n)

# prefix sum, hash table
class Solution(object):
    def minSizeSubarray(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        INF = float("inf")
        q, target = divmod(target, sum(nums))
        if not target:
            return q*len(nums)
        result = INF
        lookup = {0:-1}
        curr = 0
        for right in xrange((len(nums)-1)+(len(nums)-1)):
            curr += nums[right%len(nums)]
            if curr-target in lookup:
                result = min(result, right-lookup[curr-target])
            lookup[curr] = right
        return result+q*len(nums) if result != INF else -1
