# Time:  O(nlogr)
# Space: O(1)

# array
class Solution(object):
    def minMergedInteger(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def length(x):
            result = 0
            while x:
                x //= 10
                result += 1
            return result

        def f(x, y):
            return x*(10**length(y))+y
    
        return min(f(nums[2*i], nums[2*i+1]) for i in xrange(len(nums)//2))
