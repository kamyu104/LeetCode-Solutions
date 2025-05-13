# Time:  O(n)
# Space: O(n)

# greedy, mono stack
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        stk = [0]
        for x in nums:
            while stk and stk[-1] > x:
                stk.pop()
            if stk[-1] < x:
                result += 1
                stk.append(x)
        return result
