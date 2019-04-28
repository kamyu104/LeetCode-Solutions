# Time:  O(1)
# Space: O(1)

class Solution(object):
    def numMovesStones(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        s = [a, b, c]
        s.sort()
        if s[0]+1 == s[1] and s[1]+1 == s[2]:
            return [0, 0]
        return [1 if s[0]+2 >= s[1] or s[1]+2 >= s[2] else 2, s[2]-s[0]-2]
