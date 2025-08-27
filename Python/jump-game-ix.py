# Time:  O(n)
# Space: O(1)

# graph, prefix sum
class Solution(object):
    def maxValue(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [0]*len(nums)
        result[0] = nums[0]
        for i in xrange(len(nums)-1):
            result[i+1] = max(result[i], nums[i+1])
        mn = float("inf")
        for i in reversed(xrange(len(nums))):
            if result[i] > mn:
                result[i] = result[i+1]
            mn = min(mn, nums[i])
        return result


# Time:  O(n)
# Space: O(n)
# graph, prefix sum
class Solution2(object):
    def maxValue(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        suffix = [float("inf")]*(len(nums)+1)
        for i in reversed(xrange(len(nums))):
            suffix[i] = min(suffix[i+1], nums[i])
        result = [0]*len(nums)
        mx = left = 0
        for right in xrange(len(nums)):
            mx = max(mx, nums[right])
            if mx > suffix[right+1]:
                continue
            while left <= right:
                result[left] = mx
                left += 1
        return result
