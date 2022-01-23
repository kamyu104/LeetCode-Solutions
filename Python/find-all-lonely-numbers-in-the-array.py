# Time:  O(n)
# Space: O(n)

# freq table
class Solution(object):
    def findLonely(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        cnt = collections.Counter(nums)
        return [x for x in nums if cnt[x] == 1 and x-1 not in cnt and x+1 not in cnt]
