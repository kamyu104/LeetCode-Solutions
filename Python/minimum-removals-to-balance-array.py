# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers
class Solution(object):
    def minRemoval(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        left = 0
        for right in xrange(len(nums)):
            if nums[left]*k < nums[right]:
                left += 1
        return left


# Time:  O(nlogn)
# Space: O(1)
# sort, two pointers
class Solution2(object):
    def minRemoval(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result = left = 0
        for right in xrange(len(nums)):
            while nums[left]*k < nums[right]:
                left += 1
            result = max(result, right-left+1)
        return len(nums)-result
