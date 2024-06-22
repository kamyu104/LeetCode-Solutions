# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt = 1 if len(nums) == 1 or cmp(nums[0], nums[1]) == 0 else 2
        for i in xrange(2, len(nums)):
            cnt = 1 if cmp(nums[i-1], nums[i]) == 0 else cnt+1 if cmp(nums[i-2], nums[i-1]) == cmp(nums[i-1], nums[i]) else 2
            result = max(result, cnt)
        return result


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt1 = cnt2 = 1
        for i in xrange(1, len(nums)):
            cnt1 = cnt1+1 if nums[i-1] < nums[i] else 1
            cnt2 = cnt2+1 if nums[i-1] > nums[i] else 1
            result = max(result, cnt1, cnt2)
        return result


# Time:  O(n)
# Space: O(1)
# array
class Solution3(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def f(compare):
            result = l = 0
            for i in xrange(len(nums)):
                l += 1
                if i+1 == len(nums) or not compare(nums[i], nums[i+1]):
                    result = max(result, l)
                    l = 0
            return result

        return max(f(lambda x, y: x < y), f(lambda x, y: x > y))
