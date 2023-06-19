# Time:  O(nlogn)
# Space: O(1)

# sort, math
class Solution(object):
    def sumDistance(self, nums, s, d):
        """
        :type nums: List[int]
        :type s: str
        :type d: int
        :rtype: int
        """
        MOD = 10**9+7
        for i in xrange(len(nums)):
            nums[i] += d if s[i] == 'R' else -d
        nums.sort()
        return reduce(lambda x, y: (x+y)%MOD, ((i-(len(nums)-(i+1)))*x for i, x in enumerate(nums)))
