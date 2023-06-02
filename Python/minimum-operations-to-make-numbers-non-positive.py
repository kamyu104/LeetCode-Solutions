# Time:  O(nlogr)
# Space: O(1)

# binary search, greedy
class Solution(object):
    def minOperations(self, nums, x, y):
        """
        :type nums: List[int]
        :type x: int
        :type y: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        def check(total):
            return sum(ceil_divide(max(v-min(ceil_divide(v, y), total)*y, 0), x-y) for v in nums) <= total
    
        left, right = 1, ceil_divide(max(nums), y)
        while left <= right:
            mid = left+(right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return left
