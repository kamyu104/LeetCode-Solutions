# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def longestArithmetic(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def f(nums):
            result = 2
            diff = nums[1]-nums[0]
            left = 0
            for right in xrange(2, len(nums)):
                curr = nums[right]-nums[right-1]
                if curr == diff:
                    result = max(result, right-left+1)
                    continue
                r = right
                while r+1 < len(nums) and nums[r+1]-(nums[r] if r != right else nums[r-1]+diff) == diff:
                    r += 1
                result = max(result, r-left+1)
                left = right-1
                diff = curr
            return result

        result = f(nums)
        nums.reverse()
        result = max(result, f(nums))
        return result
