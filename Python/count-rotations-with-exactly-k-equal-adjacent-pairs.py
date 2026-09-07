# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def countRotations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        total = sum(s[i] == s[(i+1)%len(s)] for i in xrange(len(s)))
        return total if total-1 == k else len(s)-total if total == k else 0
