# Time:  O(n)
# Space: O(n)

# prefix sum
class Solution(object):
    def firstStableIndex(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        right = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(len(nums))):
            right[i] = min(right[i+1], nums[i])
        left = 0
        for i in xrange(len(nums)):
            left = max(left, nums[i])
            if left-right[i] <= k:
                return i
        return -1


# Time:  O(n)
# Space: O(n)
# prefix sum
class Solution2(object):
    def firstStableIndex(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            left[i+1] = max(left[i], nums[i])
        right = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(len(nums))):
            right[i] = min(right[i+1], nums[i])
        return next((i for i in xrange(len(nums)) if left[i+1]-right[i] <= k), -1)
