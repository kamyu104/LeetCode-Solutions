# Time:  O(n^2)
# Space: O(1)

# string
class Solution(object):
    def stringSequence(self, target):
        """
        :type target: str
        :rtype: List[str]
        """
        return [target[:i]+chr(x) for i in xrange(len(target)) for x in xrange(ord('a'), ord(target[i])+1)]
