# Time:  O(1)
# Space: O(1)

# math, parity
class Solution(object):
    def checkTwoChessboards(self, coordinate1, coordinate2):
        """
        :type coordinate1: str
        :type coordinate2: str
        :rtype: bool
        """
        def parity(a):
            return reduce(lambda accu, x: (accu+x)%2, (ord(x) for x in a), 0)
        
        return parity(coordinate1) == parity(coordinate2)
