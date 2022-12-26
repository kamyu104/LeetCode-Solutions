# Time:  O(n)
# Space: O(1)

# dp, math
class Solution(object):
    def evenProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = (len(nums)+1)*len(nums)//2
        cnt = 0
        for x in nums:
            cnt = cnt+1 if x%2 else 0
            result -= cnt
        return result


# Time:  O(n)
# Space: O(1)
# dp, math
class Solution2(object):
    def evenProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt = 0
        for i, x in enumerate(nums):
            if x%2 == 0:
                cnt = i+1
            result += cnt
        return result
