# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = sum(int(c) == i%2 for i, c in enumerate(s))
        return min(cnt, len(s)-cnt)
