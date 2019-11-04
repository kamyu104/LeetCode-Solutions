# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def missingElement(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def missing_count(nums, x):
            return (nums[x]-nums[0]+1)-(x-0+1)

        def check(nums, k, x):
            return k <= missing_count(nums, x)

        left, right = 0, len(nums)-1
        while left <= right:
            mid = left + (right-left)//2
            if check(nums, k, mid):
                right = mid-1
            else:
                left = mid+1
        assert(not check(nums, k, right))
        return nums[right] + (k-missing_count(nums, right))
