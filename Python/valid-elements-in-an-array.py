# Time:  O(n)
# Space: O(n)

# prefix sum
class Solution(object):
    def findValidElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        right = [True]*len(nums)
        mx = 0
        for i in reversed(xrange(len(nums))):
            right[i] = mx < nums[i]
            mx = max(mx, nums[i])
        result = []
        mx = 0
        for i in xrange(len(nums)):
            left = mx < nums[i]
            mx = max(mx, nums[i])
            if left or right[i]:
                result.append(nums[i])
        return result


# Time:  O(n)
# Space: O(n)
# prefix sum
class Solution2(object):
    def findValidElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = [True]*len(nums)
        mx = 0
        for i in xrange(len(nums)):
            left[i] = mx < nums[i]
            mx = max(mx, nums[i])
        right = [True]*len(nums)
        mx = 0
        for i in reversed(xrange(len(nums))):
            right[i] = mx < nums[i]
            mx = max(mx, nums[i])
        return [nums[i] for i in xrange(len(nums)) if left[i] or right[i]]
