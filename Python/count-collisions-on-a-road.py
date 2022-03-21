# Time:  O(n)
# Space: O(1)

# counting, simulation
class Solution(object):
    def countCollisions(self, directions):
        """
        :type directions: str
        :rtype: int
        """
        result = cnt = 0
        smooth = 1
        for x in directions:
            if x == 'R':
                cnt += 1
            elif x == 'S' or (cnt or not smooth):
                result += cnt+int(x == 'L')
                cnt = smooth = 0
        return result
