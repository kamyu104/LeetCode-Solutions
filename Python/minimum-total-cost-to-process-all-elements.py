# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def minimumCost(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        def ceil_divide(a, b):
            return (a+b-1)//b
        
        cnt = ceil_divide(sum(nums), k)-1
        return ((1+cnt)*cnt//2)%MOD
