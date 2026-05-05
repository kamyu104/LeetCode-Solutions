# Time:  O(n)
# Space: O(1)

# freq table
class Solution(object):
    def countOppositeParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [0]*len(nums)
        cnt = [0]*2
        for i in reversed(xrange(len(nums))):
            result[i] = cnt[1^(nums[i]%2)]
            cnt[nums[i]%2] += 1
        return result
