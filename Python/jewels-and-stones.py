# Time:  O(m + n)
# Space: O(n)

class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        lookup = set(J)
        return sum(s in lookup for s in S)
        
