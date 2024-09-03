# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def stringHash(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        result = (chr(ord('a')+reduce(lambda accu, x: (accu+x)%26,  (ord(s[i+j])-ord('a') for j in xrange(k)), 0)) for i in xrange(0, len(s), k))
        return "".join(result)
