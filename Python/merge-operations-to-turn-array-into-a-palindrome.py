# Time:  O(n)
# Space: O(1)

# constructive algorithms, greedy, two pointers
class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        left, right = 0, len(nums)-1
        l, r = nums[left], nums[right]
        while left < right:
            if l == r:
                left += 1
                right -= 1
                l, r = nums[left], nums[right]
                continue
            if l < r:
                left += 1
                l += nums[left]
            else:
                right -= 1
                r += nums[right]
            result += 1
        return result
            
