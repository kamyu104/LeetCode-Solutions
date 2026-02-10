# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def longestAlternating(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = up1 = up0 = down1 = down0 = 1
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                up1, up0, down1, down0 = down1+1, down0+1, down0, 1
            elif nums[i] > nums[i+1]:
                up1, up0, down1, down0 = up0, 1, up1+1, up0+1
            else:
                up1, up0, down1, down0 = up0, 1, down0, 1
            result = max(result, up1, down1)
        return result


# Time:  O(n)
# Space: O(n)
# prefix sum
class Solution2(object):
    def longestAlternating(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = [1]*len(nums)
        for i in xrange(1, len(nums)):
            diff = cmp(nums[i-1], nums[i])
            if not diff:
                continue
            left[i] = left[i-1]+1 if i-2 >= 0 and cmp(nums[i-2], nums[i-1]) == -diff else 2
        right = [1]*len(nums)
        for i in reversed(xrange(len(nums)-1)):
            diff = cmp(nums[i], nums[i+1])
            if not diff:
                continue
            right[i] = right[i+1]+1 if i+2 < len(nums) and cmp(nums[i+1], nums[i+2]) == -diff else 2
        result = max(left)
        for i in xrange(1, len(nums)-1):
            diff = cmp(nums[i-1], nums[i+1])
            if not diff:
                continue
            l = (left[i-1] if i-2 >= 0 and cmp(nums[i-2], nums[i-1]) == -diff else 1)
            r = (right[i+1] if i+2 < len(nums) and cmp(nums[i+1], nums[i+2]) == -diff else 1)
            result = max(result, l+r)
        return result
