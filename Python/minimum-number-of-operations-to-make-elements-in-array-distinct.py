# Time:  O(n + r)
# Space: O(r)

# freq table
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        mx = max(nums)
        cnt = [0]*mx
        for i in reversed(xrange(len(nums))):
            cnt[nums[i]-1] += 1
            if cnt[nums[i]-1] == 2:
                return ceil_divide(i+1, 3)
        return 0
