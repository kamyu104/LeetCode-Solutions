# Time:  O(n)
# Space: O(n)

# combinatorics, mono stack
class Solution(object):
    def countGoodSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def is_proper_subset(a, b):
            return a != b and a|b == b

        def is_subset(a, b):
            return a|b == b

        
        right = [len(nums)]*len(nums)
        stk = []
        for i in reversed(xrange(len(nums))):
            while stk and is_subset(nums[stk[-1]], nums[i]):
                stk.pop()
            right[i] = stk[-1] if stk else len(nums)
            stk.append(i)
        result, left = 0, -1
        stk = []
        for i in xrange(len(nums)):
            while stk and is_proper_subset(nums[stk[-1]], nums[i]):
                stk.pop()
            left = stk[-1] if stk else -1
            stk.append(i)
            result += (i-left)*(right[i]-i)
        return result


# Time:  O(n)
# Space: O(n)
# combinatorics, mono stack
class Solution2(object):
    def countGoodSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def is_proper_subset(a, b):
            return a != b and a|b == b

        def is_subset(a, b):
            return a|b == b

        left = [-1]*len(nums)
        stk = []
        for i in reversed(xrange(len(nums))):
            while stk and not is_proper_subset(nums[i], nums[stk[-1]]):
                left[stk.pop()] = i
            stk.append(i)
        right = [len(nums)]*len(nums)
        stk = []
        for i in xrange(len(nums)):
            while stk and not is_subset(nums[i], nums[stk[-1]]):
                right[stk.pop()] = i
            stk.append(i)
        return sum((i-left[i])*(right[i]-i) for i in xrange(len(nums)))
