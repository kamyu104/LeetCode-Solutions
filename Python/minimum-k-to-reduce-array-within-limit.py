# Time:  O(nlogr + nlogn)
# Space: O(1)

# binary search
class Solution(object):
    def minimumK(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(k):
            return sum((ceil_divide(x, k)) for x in nums) <= k**2

        right = max(max(nums), int(ceil(sqrt(len(nums)))))
        return binary_search(1, right, check)
