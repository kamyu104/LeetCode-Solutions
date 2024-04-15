# Time:  O(n)
# Space: O(n)

# mono stack, combinatorics
class Solution(object):
    def numberOfSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        stk = []
        for x in nums:
            while stk and stk[-1][0] < x:
                stk.pop()
            if not stk or stk[-1][0] != x:
                stk.append([x, 0])
            stk[-1][1] += 1
            result += stk[-1][1]
        return result
