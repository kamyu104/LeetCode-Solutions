# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def divideString(self, s, k, fill):
        """
        :type s: str
        :type k: int
        :type fill: str
        :rtype: List[str]
        """
        return [s[i:i+k] + fill*(i+k-len(s)) for i in xrange(0, len(s), k)]
