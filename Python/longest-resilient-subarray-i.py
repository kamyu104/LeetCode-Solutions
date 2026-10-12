# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def resilientSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(nums)):
            if nums[left]%k != nums[right]%k:
                left = right
            if nums[left]*((right-left+1)-1)%k == 0:
                result = max(result, right-left+1)
        return result


# Time:  O(n^2)
# Space: O(1)
# brute force
class Solution2(object):
    def resilientSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        for i in xrange(len(nums)):
            for j in xrange(i, len(nums)):
                if nums[j]%k != nums[i]%k:
                    break
                if nums[i]*((j-i+1)-1)%k == 0:
                    result = max(result, j-i+1)
        return result
