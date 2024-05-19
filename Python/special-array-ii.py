# Time:  O(n + q)
# Space: O(n)

# prefix sum
class Solution(object):
    def isArraySpecial(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        prefix = [0]*len(nums)
        for i in xrange(len(nums)-1):
            prefix[i+1] = prefix[i]+int(nums[i+1]&1 != nums[i]&1)
        result = [False]*len(queries)
        for i, (l, r) in enumerate(queries):
            result[i] = prefix[r]-prefix[l] == r-l
        return result
