# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def maximumValue(self, n, s, m):
        """
        :type n: int
        :type s: int
        :type m: int
        :rtype: int
        """
        return s+(n//2)*m-((n-1)//2)*1+(n%2 if n != 1 else 0)
