# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def furthestDistanceFromOrigin(self, moves):
        """
        :type moves: str
        :rtype: int
        """
        curr = cnt = 0
        for x in moves:
            if x == 'L':
                curr -= 1
            elif x == 'R':
                curr += 1
            else:
                cnt += 1
        return abs(curr)+cnt
