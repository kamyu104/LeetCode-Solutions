# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = curr = 0
        for c in s:
            curr = curr+1 if c == ']' else curr-1
            result = max(result, curr)
        return (result+1)//2
