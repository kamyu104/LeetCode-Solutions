# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt1 = cnt2 = 1
        for i in xrange(1, len(nums)):
            if nums[i-1] < nums[i]:
                cnt1 += 1
                cnt2 = 1
            elif nums[i-1] > nums[i]:
                cnt2 += 1
                cnt1 = 1
            else:
                cnt1 = cnt2 = 1
            result = max(result, cnt1, cnt2)
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
        def f(compare):
            result = l = 0
            for i in xrange(len(nums)):
                l += 1
                if i+1 == len(nums) or not compare(nums[i], nums[i+1]):
                    result = max(result, l)
                    l = 0
            return result

        return max(f(lambda x, y: x < y), f(lambda x, y: x > y))
