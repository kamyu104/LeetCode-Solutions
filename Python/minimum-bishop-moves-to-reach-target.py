# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minBishopMoves(self, source, target):
        """
        :type source: List[int]
        :type target: List[int]
        :rtype: int
        """
        if (source[0]+target[0])%2 != (source[1]+target[1])%2:
            return -1
        return 1 if abs(source[0]-target[0]) == abs(source[1]-target[1]) else 2
