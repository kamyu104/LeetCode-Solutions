# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def incremovableSubarrayCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for j in reversed(xrange(1, len(nums))):
            if not nums[j-1] < nums[j]:
                break
        else:
            return (len(nums)+1)*len(nums)//2
        result = len(nums)-j+1
        for i in xrange(len(nums)-1):
            while j < len(nums) and not (nums[i] < nums[j]):
                j += 1
            result += len(nums)-j+1
            if not (nums[i] < nums[i+1]):
                break
        return result


# Time:  O(n^3)
# Space: O(1)
# brute force
class Solution2(object):
    def incremovableSubarrayCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum((left == 0 or right == len(nums)-1 or nums[left-1] < nums[right+1]) and
                   all(nums[i] < nums[i+1] for i in xrange(left-1)) and
                   all(nums[i] < nums[i+1] for i in xrange(right+1, len(nums)-1))
                   for left in xrange(len(nums)) for right in xrange(left, len(nums)))
