# Time:  O(n)
# Space: O(1)

# combinatorics
class Solution(object):
    def countSubstrings(self, s, c):
        """
        :type s: str
        :type c: str
        :rtype: int
        """
        n = s.count(c)
        return (n+1)*n//2
