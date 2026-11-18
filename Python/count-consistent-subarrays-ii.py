# Time:  O(n)
# Space: O(n)

# mono stack
class Solution(object):
    def countConsistent(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def is_superset(a, b):
            return a&b == b

        def is_strict_superset(a, b):
            return a&b == b and a != b

        left, stk = [], []
        for i, x in enumerate(nums):
            while stk and is_superset(nums[stk[-1]], x):
                stk.pop()
            left.append(stk[-1] if stk else -1)
            stk.append(i)
        result, stk = 0, []
        for i in reversed(xrange(len(nums))):
            x = nums[i]
            while stk and is_strict_superset(nums[stk[-1]], x):
                stk.pop()
            right = stk[-1] if stk else len(nums)
            result += (i-left[i])*(right-i)
            stk.append(i)
        return result
