# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def getEncryptedString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return "".join(s[(i+k)%len(s)] for i in xrange(len(s)))
