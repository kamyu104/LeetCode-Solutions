# Time:  O(n)
# Space: O(1)

# sort
class Solution(object):
    def minUnlockedIndices(self, nums, locked):
        """
        :type nums: List[int]
        :type locked: List[int]
        :rtype: int
        """
        result = mx = cnt = 0
        for i in xrange(len(nums)):
            if mx < nums[i]:
                mx = nums[i]
                cnt = 0
            elif mx > nums[i]:
                if mx != nums[i]+1:
                    return -1
                result += cnt
                cnt = 0
            cnt += locked[i]
        return result
