# Time:  O(n)
# Space: O(1)

# simulation
class Solution(object):
    def maxDistance(self, moves):
        """
        :type moves: str
        :rtype: int
        """
        x = y = cnt = 0
        for c in moves:
            if c == 'U':
                y += 1
            elif c == 'D':
                y -= 1
            elif c == 'L':
                x -= 1
            elif c == 'R':
                x += 1
            else:
                cnt += 1
        return abs(x)+abs(y)+cnt


# Time:  O(n)
# Space: O(1)
# simulation
class Solution2(object):
    def maxDistance(self, moves):
        """
        :type moves: str
        :rtype: int
        """
        return abs(moves.count('U')-moves.count('D'))+abs(moves.count('L')-moves.count('R'))+moves.count('_')
